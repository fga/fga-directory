_More detailed instructions are forthcoming. Please seen this [google doc](https://docs.google.com/document/d/1gzlRvXYSfyGZRoWP_stHZAzGV66jR9bBFhREeqcBPdw/edit#heading=h.bcdf9msxnwpl) for more information._


How to embed the #occupy directory map on your website
======================================================



You are free to embed the #occupy directory map on your website by including the following iframe:

```html
<iframe id="embed" src="http://directory.occupy.local/embed/v1/index.html" style="border:0; height:100%; width:100%; position:absolute;"></iframe>
```

The map will scale to fit the container it is in. To make the map an exact size, set a width and height using CSS on a wrapper element, like so:

```html
<div id="embed-wrapper" style="width:960px; height:700px"
  <iframe id="embed" src="http://directory.occupy.local/embed/v1/index.html" style="border:0; height:100%; width:100%; position:absolute;" marginwidth="0" marginheight="0" frameborder="0" vspace="0" hspace="0" allowtransparency="true" scrolling="no" ></iframe>
</div>
```

Above, we have also added some declarations of greater cross-browser compatibility.


Customizing the map zoom level and centerpoint
----------------------------------------------

You can optionally pass parameters for zoom-level/latitude/longitude to the URL to set the zoom level and the center point of the map so that it scales most appropriately to your website layout. The url below shows the appropriate syntax, and also the default parameters used for the embed.

```html
<iframe id="embed" http://directory.occupy.net/embed/v1/index.html#2.00/-16.2/10.0" ></iframe>
```

**Zoom-level:** a number between 2.00 - 11.00

**Latitude/longitude:** any point in the world. 

_**NOTE** that the map will center based on its extents, so if you set the zoom level to 2, and try and center to Australia, the centerpoint will fall back to the defaults. You can shift the bounds in index.html to customize this behavior._


If you directly visit the URL emebedded in the iframe (http://directory.occupy.net/embed/v1/index.html), you can interactively pan and zoom the map in your web browser, dynamically changing the URLs parameters, which you can then grab from the address bar.