var directory = directory || {};
/*
	Function: buildConsoleObject
	Quick hack to prevent browsers w/o a console, or firebug from generating errors when console functions are called. Gets called immediately
*/

directory.tooltipTemplate = "<div class=\"detail\" id=\"occupation-{{{id}}}\">    <!-- using hCard microformat -->  <div class=\"vcard\">        <div class=\"occupation-title clearfix\">	    {{#Occupation_image-thumb}}      <div class=\"occupation-image\">        <img src=\"{{{Occupation_image-thumb}}}\" width=\"92\" height=\"92\" alt=\"{{{Title}}} image\" />      </div>	    {{/Occupation_image-thumb}}      <h3 class=\"fn org title\">      <a class=\"occupation-directory-url\"  href=\"{{{Occupy Directory URL}}}\">{{{Title}}}</a>      </h3>    </div>        <ul>      {{#Occupation website}}      <li class=\"website-url taglink\">        <a class=\"url\" title=\"Occupation Website\" target=\"_blank\" href=\"{{{Occupation website}}}\">Occupation website</a>      </li>      {{/Occupation website}}      {{#General email address}}      <li class=\"general-email-address taglink\">        <a class=\"email\" href=\"mailto:{{{General email address}}}\">{{{General email address}}}</a>      </li>      {{/General email address}}      <li class=\"adr\">                <div class=\"street\">          {{#Location Name}}<span class=\"locality\">{{{Location Name}}}</span>{{/Location Name}}          {{#Address 1}}<span class=\"street-address\">{{{Address 1}}}</span>{{/Address 1}}          {{#Address 2}}<span class=\"extended-address\">{{{Address 2}}}</span>{{/Address 2}}        </div>                <span class=\"loc\">          {{#City}}<span class=\"city\">{{{City}}}</span>{{/City}}{{#City_sub}}<span class=\"citi-sub\"> {{{City_sub}}}</span>{{/City_sub}}{{#State}}<span class=\"region\">, {{{State}}}</span> {{/State}}{{#State_sub}}<span class=\"state-sub\"> {{{State_sub}}}</span>{{/State_sub}}{{#zip-postal}}<span class=\"postal-code\">{{{zip-postal}}}</span> {{/zip-postal}}<br/>          {{#Country}}<span class=\"country-name\">{{{Country}}}</span>{{/Country}}        </span>      </li>      {{#General phone}}      <li class=\"tel general-phone taglink\">        {{{General phone}}}      </li>      {{/General phone}}    </ul>  </div><!--end vcard -->  <div class=\"info\">    {{#Founded-longdate}}    <div class=\"founded YYYY-MM-DD\">      <h5 class=\"label\">Founded</h5>      <span class=\"bday\">{{{Founded-longdate}}}</span>    </div>    {{/Founded-longdate}}            {{#Occupation description}}<p class=\"occupation-description\">{{{Occupation description}}}</p>{{/Occupation description}}    {{#General Assembly}}<p class=\"genera-assembly\">{{{General Assembly}}}</p>{{/General Assembly}}    {{#Physical occupation occurring}}<p class=\"physical-occupation-occurring\">{{{Physical occupation occurring}}}</p>{{/Physical occupation occurring}}  </div><!-- end info -->  <ul class=\"listings clearfix\">    <li>      {{#occupation_websites_extra1}}      <h5 class=\"label\">Additional Websites</h5>      <ul class=\"additional-websites clearfix\">        <li class=\"taglink\"><a target=\"_blank\" href=\"{{{occupation_websites_extra1}}}\">social 1</a></li>        {{#occupation_websites_extra2}}<li class=\"taglink\"><a target=\"_blank\" href=\"{{{occupation_websites_extra2}}}\">social 2</a></li>{{/occupation_websites_extra2}}        {{#occupation_websites_extra3}}<li class=\"taglink\"><a target=\"_blank\" href=\"{{{occupation_websites_extra3}}}\">social 3</a></li>{{/occupation_websites_extra3}}      </ul>      {{/occupation_websites_extra1}}      {{#Twitter_hashtag1}}      <h5 class=\"label\">Twitter Hash Tags</h5>      <ul class=\"twitter-hashtags clearfix\">        <li class=\"twitter-hashtags taglink\"><a target=\"_blank\" href=\"#\">{{{Twitter_hashtag1}}}</a></li>        {{#Twitter_hashtag2}}<li class=\"twitter-hashtags taglink\"><a target=\"_blank\" href=\"#\">{{{Twitter_hashtag2}}}</a></li>{{/Twitter_hashtag2}}        {{#Twitter_hashtag3}}<li class=\"twitter-hashtags taglink\"><a target=\"_blank\" href=\"#\">{{{Twitter_hashtag3}}}</a></li>{{/Twitter_hashtag3}}      </ul>      {{/Twitter_hashtag1}}            {{#Twitter_account1}}      <h5 class=\"label\">Twitter Accounts</h5>      <ul class=\"twitter-accounts clearfix\">       <li class=\"twitter-accounts taglink\"><a target=\"_blank\" href=\"http://twitter.com/{{{Twitter_account1}}}\">{{{Twitter_account1}}}</a></li>        {{#Twitter_account2}}<li class=\"twitter-accounts taglink\"><a target=\"_blank\" href=\"http://twitter.com/{{{Twitter_account2}}}\">{{{Twitter_account2}}}</a></li>{{/Twitter_account2}}        {{#Twitter_account3}}<li class=\"twitter-accounts taglink\"><a target=\"_blank\" href=\"http://twitter.com/{{{Twitter_account3}}}\">{{{Twitter_account3}}}</a></li>{{/Twitter_account3}}      </ul>      {{/Twitter_account1}}                  {{#Youtube1}}      <h5 class=\"label\">Youtube Channels</h5>      <ul class=\"youtube-sites clearfix\">        <li class=\"youtube-channel-urls taglink\"><a target=\"_blank\" href=\"{{{Youtube1}}}\">Channel 1</a></li>        {{#Youtube2}}<li class=\"youtube-channel-urls taglink\"><a target=\"_blank\" href=\"{{{Youtube2}}}\">Channel 2</a></li>{{/Youtube2}}      </ul>      {{/Youtube1}}            {{#live_video1}}      <h5 class=\"label\">Video Streams</h5>      <ul class=\"video-sites clearfix\">        <li class=\"live-video-streams taglink\"><a target=\"_blank\" href=\"{{{live_video1}}}\">Stream 1</a></li>        {{#live_video2}}<li class=\"live-video-streams taglink\"><a target=\"_blank\" href=\"{{{live_video2}}}\">Stream 2</a></li>{{/live_video2}}      </ul>      {{/live_video1}}      <h5 class=\"label\">Social Media</h5>      <ul class=\"social-media-sites clearfix\">        {{#Facebook1}}<li class=\"facebook-pages taglink\"><a  target=\"_blank\" href=\"{{{Facebook1}}}\">Primary Facebook</a></li>{{/Facebook1}}        {{#Facebook2}}<li class=\"facebook-pages taglink\"><a  target=\"_blank\" href=\"{{{Facebook2}}}\">Other Facebook</a></li>{{/Facebook2}}        {{#Meetup URL}}<li class=\"meetup-url taglink\"><a  target=\"_blank\" href=\"{{{Meetup URL}}}\">MeetUp</a></li>{{/Meetup URL}}        {{#social_media_extra1}}<li class=\"additional-social-media-sites taglink\"><a  target=\"_blank\" href=\"{{{social_media_extra1}}}\">Other Social Media A</a></li>{{/social_media_extra1}}        {{#social_media_extra2}}<li class=\"additional-social-media-sites taglink\"><a  target=\"_blank\" href=\"{{{social_media_extra2}}}\">Other Social Media B</a></li>{{/social_media_extra2}}        {{#social_media_extra3}}<li class=\"additional-social-media-sites taglink\"><a  target=\"_blank\" href=\"{{{social_media_extra3}}}\">Other Social Media C</a></li>{{/social_media_extra3}}              </ul>      {{#Newspaper URL}}      <h5 class=\"label\">Newspapers</h5>      <ul class=\"newspapers clearfix\">        <li class=\"newspaper-urls taglink\"><a target=\"_blank\"  href=\"{{{Newspaper URL}}}\">Newspaper</a></li>      </ul>      {{/Newspaper URL}}      {{#RSS1}}      <h5 class=\"label\">RSS Feeds</h5>      <ul class=\"feeds clearfix\">        <li class=\"rss-feeds taglink\"><a target=\"_blank\" href=\"{{{RSS1}}}\">RSS 1</a></li>        {{#RSS2}}<li class=\"rss-feeds taglink\"><a target=\"_blank\" href=\"{{{RSS2}}}\">RSS 2</a></li>{{/RSS2}}</ul>{{/RSS1}}        </li>  </ul><!-- end listing --></div><!-- end tooltip-inner -->";

if (!window.console ){
	var names = ["log", "debug", "info", "warn", "error", "assert", "dir", "dirxml", "group", "groupEnd", "time", "timeEnd", "count", "trace", "profile", "profileEnd"];
 	window.console = {};
  for (var i = 0; i < names.length; ++i){ window.console[names[i]] = function() {}; }
	names = null;
}

	directory.movetip = function() {
    var popped = false,
        t = {},
        _tooltipOffset,
        _contextOffset,
        tooltip,
        parent;

    function moveTooltip(e) {
       var eo = wax.u.eventoffset(e);
       // faux-positioning
       if ((_tooltipOffset.height + eo.y) >
           (_contextOffset.top + _contextOffset.height) &&
           (_contextOffset.height > _tooltipOffset.height)) {
           eo.y -= _tooltipOffset.height;
           tooltip.className += ' flip-y';
       }

       // faux-positioning
       if ((_tooltipOffset.width + eo.x) >
           (_contextOffset.left + _contextOffset.width)) {
           eo.x -= _tooltipOffset.width;
           tooltip.className += ' flip-x';
       }

       tooltip.style.left = eo.x + 'px';
       tooltip.style.top = eo.y + 'px';
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
        //if (popped) return;
        if ((o.e.type === 'mousemove' || !o.e.type)) {
            content = o.formatter({ format: 'teaser' }, o.data);
            if (!content) return;
            hide();
            parent.style.cursor = 'pointer';
            tooltip = document.body.appendChild(getTooltip(content));
        } else {
            content = o.formatter({ format: 'teaser' }, o.data);
            if (!content) return;
            hide();
            var tt = document.body.appendChild(getTooltip(content));
            tt.className += ' map-popup';

            var close = tt.appendChild(document.createElement('a'));
            close.href = '#close';
            close.className = 'close';
            close.innerHTML = 'Close';

            //popped = true;

            tooltip = tt;

            _tooltipOffset = wax.u.offset(tooltip);
            _contextOffset = wax.u.offset(parent);
            moveTooltip(o.e);

            bean.add(close, 'click touchend', function closeClick(e) {
                e.stop();
                hide();
                //popped = false;
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
        //if (!popped) 
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
		
		directory.initMap = function( el ){

			directory.map.container = el;

			$('#sidebar a.close').click( function(){
				$("#sidebar").addClass( 'hidden' );
			});

			mapbox.load( directory.map.id, function( o ){
				
				var eventHandlers = [
					easey_handlers.TouchHandler(),
        	easey_handlers.DragHandler(),
        	easey_handlers.DoubleClickHandler()
        ]

				var map  = mapbox.map('map', null, null, eventHandlers );
				map.addLayer( o.layer ).zoom( directory.map.zoom.init ).center( directory.map.center );				

				map.interaction.auto();
				map.interaction.on({
					on: function( obj ){
						if( obj.e.type == 'click' ){
							var sidebarContent = Mustache.to_html( directory.tooltipTemplate , obj.data );
							$('#sidebar').removeClass('hidden');
							$('#sidebar .content').html( sidebarContent );							
						}
					}
				});
				$( directory.map.options ).each( function( i, opt ){
					console.log( this );
					map.ui[this].add();
				});
//				map.ui.refresh();
				map.setPanLimits( directory.map.bounds );
				map.setZoomRange( directory.map.zoom.min, directory.map.zoom.max );
				
				map.refresh();
			});

			
		}
		


$( function(){
	directory.initMap( $('#map')[0] );
});

