Drupal.behaviors.directory = {

	attach: function(context, settings){

        Drupal.behaviors.directory.map = jQuery( '#directory-map-wrapper' )[0];

		function resize_map(){
			var winh = jQuery(window).height();
            map = jQuery( Drupal.behaviors.directory.map );
			map.css( { 'width': '100%', 'height': winh - map.offset().top } );
		}

		if( Drupal.behaviors.directory.map ) {

			resize_map();
			jQuery(window).resize( function(){
				resize_map();
			});

		  /* todo: move these configuration variables to the module admin */
			directory.map = {
				id: 'occupydirectory.map-1tyybpog',
				// the center point can be redefined by the world bounds
				center: { lat: 10.2, lon: 6.8 },
				// bounds are described as [ N, W, S, E ]
				bounds: [ { lat: 75.6722, lon: -180 } , { lat: -81.9, lon: 200 } ],
				zoom: { init:2,  min: 2 , max: 11 },
				options: [ 'share', 'legend','zoomer', 'zoombox', 'hash' ]
			};
			directory.init_map( jQuery( '#directory-map-wrapper' )[0], directory.map );
		}

	}

};

var directory = directory || {};

directory.tooltipTemplate = "<div class=\"detail\" id=\"occupation-{{{id}}}\"><!-- using hCard microformat --><div class=\"vcard\"><div class=\"occupation-title clearfix\"><h3 class=\"fn org title\"><a class=\"occupation-directory-url\" href=\"{{{Occupy Directory URL}}}\">{{{Title}}}</a></h3></div></div><!-- end tooltip-inner -->";

directory.movetip = function() {

    var popped = false,
        t = {},
        _tooltipOffset,
        _contextOffset,
        tooltip,
        parent;

    function moveTooltip(e) {

       var eo = wax.u.eventoffset(e);

       var win = jQuery(window);

       if( eo.x - directory.map.offsetParent.offset().left > win.width() * .8 ){
        jQuery( tooltip ).addClass('flip-x');
        console.log( 'flip-x', tooltip );
       }

       if( eo.y + directory.map.offsetParent.offset().top > win.height() * .7 ){
        jQuery( tooltip ).addClass('flip-y');
        console.log( 'flip-y', tooltip );
       }

       tooltip.style.left = ( eo.x - directory.map.offsetParent.offset().left ) + 'px';
       tooltip.style.top = ( eo.y - directory.map.offsetParent.offset().top  ) + 'px';
    }

    // Get the active tooltip for a layer or create a new one if no tooltip exists.
    // Hide any tooltips on layers underneath this one.
    function getTooltip(feature) {
        var tooltip = document.createElement('div');
        tooltip.className = 'map-tooltip map-tooltip-0';
        tooltip.innerHTML = feature;
        return tooltip;
    }

    // Hide a given tooltip.
    function hide() {
        if (tooltip) {
          tooltip.parentNode.removeChild(tooltip);
          tooltip = null;
        }
    }

    function on(o) {

        var content;

        if ((o.e.type === 'mousemove' || !o.e.type)) {
            content = o.formatter({ format: 'teaser' }, o.data);
            if (!content) return;
            hide();
            parent.style.cursor = 'pointer';
            tooltip = directory.map.overlay.appendChild(getTooltip(content));
        } else {
            content = o.formatter({ format: 'teaser' }, o.data);
            if (!content) return;
            hide();
            var tt = directory.map.overlay.appendChild(getTooltip(content));
            tt.className += ' map-popup';

            // var close = tt.appendChild(document.createElement('a'));
            // close.href = '#close';
            // close.className = 'close';
            // close.innerHTML = 'Close';

            //popped = true;

            tooltip = tt;

            _tooltipOffset = wax.u.offset(tooltip);
            _contextOffset = wax.u.offset(parent);
            moveTooltip(o.e);

            bean.add(close, 'click touchend', function closeClick(e) {
                e.stop();
                hide();
            });
        }

        if (tooltip) {
          _tooltipOffset = wax.u.offset(tooltip);
          _contextOffset = wax.u.offset(parent);
          moveTooltip(o.e);
        }

    }

    function off() {
        parent.style.cursor = 'default';
        hide();
    }

    t.parent = function(x) {
        if (!arguments.length) return parent;
        parent = x;
        return t;
    };

    t.events = function() {
        return {
            on: on,
            off: off
        };
    };

    return t;
};

// override mabox interaction auto... not the best way, but seems to work fine.
// kind of tangly to cut through the layers otherwise
mapbox.interaction = function() {

    var interaction = wax.mm.interaction(),
        auto = false;

    interaction.refresh = function() {
        var map = interaction.map();
        if (!auto || !map) return interaction;
        for (var i = map.layers.length - 1; i >= 0; i --) {
            var tj = map.layers[i].tilejson && map.layers[i].tilejson();
            if (tj && tj.template) return interaction.tilejson(tj);
        }
        return interaction.tilejson({});
    };

    interaction.auto = function() {
        auto = true;
        interaction.on( directory.movetip()
            .parent(interaction.map().parent)
            .events());
        return interaction.refresh();
    };

    return interaction;
};

directory.calculateEmbedLink = function( tj ){
    var l = window.location;
    return "<div id='embed-wrapper' style='width:960px; height:700px'><iframe id='directory-embed' width='960' height='600' style='border:0; height:100%; width:100%; position:absolute;' marginwidth='0' marginheight='0' frameborder='0' vspace='0' hspace='0' allowtransparency='true' scrolling='no' ></iframe><script type='text/javascript'>document.getElementById('directory-embed').src = '" + l.pathname + "?phostname='+window.location.hostname+'" + l.hash + "';</script></div>";
}

directory.share = function(map, tilejson) {
    tilejson = tilejson || {};
    var link = document.createElement('a');
    var close = document.createElement('a');
    var embed = document.createElement('textarea');
    var share = document.createElement('div');
    var popup = document.createElement('div');
    var elements = [link, close, embed, share, popup];

    if (typeof com !== 'undefined') {
        var mm = com.modestmaps;
        for (var i = 0; i < elements.length; i++) {
            mm.addEvent(elements[i], 'mousedown', function(e) { mm.cancelEvent(e); });
            mm.addEvent(elements[i], 'dblclick', function(e) { mm.cancelEvent(e); });
        }
    }

    link.innerHTML = 'Share +';
    link.href = '#';
    link.className = 'share';
    link.onclick = link.ontouchstart = function() {
        embed.value = directory.calculateEmbedLink( tilejson );
        popup.style.display = popup.style.display === 'block' ? 'none' : 'block';
        jQuery('body').toggleClass('sharing');
        return false;
    };

    close.innerHTML = 'Close';
    close.href = '#';
    close.className = 'close button';
    close.onclick = close.ontouchstart = function() {
        popup.style.display = popup.style.display === 'block' ? 'none' : 'block';
        jQuery('body').toggleClass('sharing');
        return false;
    };
    jQuery('body').keydown(function(event) {
        if ( event.which == 27 ) {
            popup.style.display = 'none';
            jQuery('body').removeClass('sharing');
            event.preventDefault();
            return false;
        }
    });

    embed.className = 'embed';
    embed.rows = 4;
    embed.setAttribute('readonly', 'readonly');
    embed.onclick = function() {
        embed.focus();
        embed.select();
        return false;
    };

    var twitter = 'http://twitter.com/intent/tweet?status='
        + encodeURIComponent(document.title + ' (' + tilejson.webpage + ')');
    var facebook = 'https://www.facebook.com/sharer.php?u='
        + encodeURIComponent(tilejson.webpage)
        + '&t=' + encodeURIComponent(document.title);
    share.innerHTML = ('<h3>Share this map</h3>'
        + '<p><a class="facebook" target="_blank" href="{{facebook}}">Facebook</a>'
        + '<a class="twitter" target="_blank" href="{{twitter}}">Twitter</a></p>')
        .replace('{{twitter}}', twitter)
        .replace('{{facebook}}', facebook);
    share.innerHTML += '<strong>Get the embed code</strong><br />'
    share.innerHTML += '<small>Copy and paste this HTML into your website or blog.</small>';
    share.appendChild(embed);
    share.appendChild(close);

    popup.className = 'wax-share';
    popup.style.display = 'none';
    popup.appendChild(share);

    return {
        appendTo: function(elem) {
            wax.u.$(elem).appendChild(link);
            wax.u.$(elem).appendChild(popup);
            return this;
        }
    };
};

directory.init_map = function( el, options ){

	directory.map.container = jQuery( el );

    var offsetParent = directory.map.container;

    while( offsetParent[0] != jQuery( document.body )[0] ){
        if( offsetParent.offsetParent()[0] != jQuery( document.body )[0] ){
            offsetParent = offsetParent.offsetParent();
            break;
        }
    }

    directory.map.offsetParent = offsetParent;

    mapbox.load( directory.map.id, function( o ){
        
        var eventHandlers = [
            easey_handlers.TouchHandler(),
            easey_handlers.DragHandler(),
            easey_handlers.DoubleClickHandler()
        ]

        directory.map.overlay =  directory.map.container.find( '.overlay' )[0];
        var map = mapbox.map( el, null, null, eventHandlers );
        directory.map.map = map;

        map.addLayer( o.layer ).zoom( directory.map.zoom.init ).center( directory.map.center );             
        map.interaction.auto();
        map.interaction.on({
            on: function( obj ){
                if( obj.e.type == 'click' ){
                    window.location.href = obj.data["Occupy Directory URL"];
                }
            }
        });

        if( jQuery.inArray('share', directory.map.options ) > -1 ){
            directory.share( map,  map.layers[0].tilejson() ).appendTo( jQuery( 'body' )[0] );
            directory.map.options.splice( jQuery.inArray( "share", directory.map.options),1);
        }
        
        jQuery( directory.map.options ).each( function( i, opt ){
            map.ui[this].add();
        });
        
        map.setPanLimits( directory.map.bounds );
        map.setZoomRange( directory.map.zoom.min, directory.map.zoom.max );             
        directory.geocoder( map );
        map.refresh();

    });	
}
		

// Bind the geocoder functionality to any div with the format
//
//     <div data-control='geocode' id="search">
//        <form class="geocode">
//          <input placeholder='Search for an address' type="text">
//          <input type='submit' />
//          <div id='geocode-error'></div>
//        </form>
//      </div>
//
directory.geocoder = function() {
    jQuery('[data-control="geocode"] form').submit(function(e) {
        e.preventDefault();
        geocode(jQuery('input[type=text]', this).val(), directory.map.map );
    });
    var geocode = function( query, m, callback  ) {
        query = encodeURIComponent(query);
        jQuery('form.geocode').addClass('loading');
        reqwest({
            url: 'http://open.mapquestapi.com/nominatim/v1/search?format=json&json_callback=callback&&limit=1&q=' + query,
            jsonpCallback: 'json_callback',
            type: 'jsonp',

            success: function (r) {
                var MM_map = directory.map.map,

                r = r[0];

                jQuery('form.geocode').removeClass('loading');

                if (r === undefined) {
                    jQuery('#geocode-error').text('This address cannot be found.').fadeIn('fast');
                } else {
                    jQuery('#geocode-error').hide();
                    MM_map.setExtent([
                        { lat: r.boundingbox[1], lon: r.boundingbox[2] },
                        { lat: r.boundingbox[0], lon: r.boundingbox[3] }
                    ]);

                    if (MM_map.getZoom() === MM_map.coordLimits[1].zoom) {
                        var point = { 'type': 'FeatureCollection',
                            'features': [{ 'type': 'Feature',
                            'geometry': { 'type': 'Point','coordinates': [r.lon, r.lat] },
                            'properties': {}
                        }]};

                        if( easey ){
                            easey().map(m)
                            .to( m.locationCoordinate({ lat: r.lat, lon: r.lon })
                            .zoomTo(11))
                            .run(2000);
                        }else{
                            MM_map.setCenter({ lat: r.lat, lon: r.lon });
                        }
                    }
                                        
                    if (callback && typeof(callback) == 'string') executeFunctionByName(callback, window);
                }
            }

        });
    };
};
