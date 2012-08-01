/*Map {
  background-color: #222;
}

#countries {
  ::outline {
    line-color: #000;
    line-width: 2;
    line-join: round;
  }
  polygon-fill: #333;
}

#cities {
  marker-width:3;
  marker-fill:#f45;
  marker-line-color:#813;
  marker-allow-overlap:true;
}
*/

@brown:#ACA68a;
@background:lighten(desaturate(@brown, 100%),20%);
@yellow:#fffc00;
@white:#ffffff;
@opacity:.1;
@ltopacity:.6;
@zoomlineco:@yellow;
@zoomlineopac:.8;
@zoomlinewidth:8;
@zoomwidth:.6;
@width:1;
@on:1;
@off:0;
@gradient:#525252;
@polygon:#282828;//darken(@background,65%);//#363636;//#ebebeb;//#363636;/
@water:#3a3a3a;//c9c9c9;
/*
Map {
  background-color:desaturate(lighten(@polygon,2.5%),25%);
  }
*/

/*#countries[SOVEREIGNT != "Canada"][SOVEREIGNT != "United States of America"], #uscanada[NAME_0="United States of America"],#uscanada[NAME_0="Canada"] {
  line-width:1;
  line-color:darken(@polygon,70%);
  line-join: round;  
  polygon-fill:darken(#242424,2%);//darken(@polygon,70%);
  polygon-opacity: 1;
  [zoom >= 8] {
    polygon-fill:transparent;
    line-color:transparent;
    }
   [zoom < 8] {
    polygon-fill:@polygon;
    line-color:@polygon;
    }
  [zoom <= 5 ] {
    polygon-fill:@polygon;
    line-color:@polygon;
    }
  [zoom <= 3] {
    polygon-fill:@polygon;
    line-color:@polygon;
    }
  [zoom <= 1] {
    polygon-fill:@polygon;
    line-color:@polygon;
    }
  }

#cover {
 [zoom >= 8] {
    polygon-fill:transparent;
    }
  [zoom < 8] {
 polygon-fill:desaturate(lighten(@polygon,2.5%),25%);
  }
  }
*/

#occupy {
   [zoom < 3] {
    marker-allow-overlap:true;
  ::highlight{
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*1;
    marker-line-color:@yellow;
    marker-width:@width*2;
    marker-line-width:@width;
    marker-line-opacity:@opacity*1;
    }
    ::highlight2 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*2;
    marker-line-color:@yellow;
    marker-width:@width*2;
    marker-line-width:@width;
    marker-line-opacity:@opacity*2;
    }
    ::highlight3 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*3;
    marker-line-color:@yellow;
    marker-width:@width*.5;
    marker-line-width:@width;
    marker-line-opacity:@opacity*3;
    }
   marker-allow-overlap:true;
   marker-fill:lighten(@yellow,55%);
   marker-opacity:.8;
   marker-width:.25;
   marker-line-color:#ffffff;
  }
  [zoom <= 4] {
    marker-allow-overlap:true;
  ::highlight{
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*1;
    marker-line-color:@yellow;
    marker-width:@width*3;
    marker-line-width:@width;
    marker-line-opacity:@opacity*1;
    }
    ::highlight2 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*2;
    marker-line-color:@yellow;
    marker-width:@width*2;
    marker-line-width:@width;
    marker-line-opacity:@opacity*2;
    }
    ::highlight3 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*3;
    marker-line-color:@yellow;
    marker-width:@width*1;
    marker-line-width:@width;
    marker-line-opacity:@opacity*3;
    }
   marker-allow-overlap:true;
   marker-fill:lighten(@yellow,55%);
   marker-opacity:.8;
   marker-width:.5;
   marker-line-color:#ffffff;
  }
 [zoom > 4] {
    marker-allow-overlap:true;
  ::highlight{
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*1;
    marker-line-color:@yellow;
    marker-width:@width*7;
    marker-line-width:@width;
    marker-line-opacity:@opacity*1;
    }
    ::highlight2 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*2;
    marker-line-color:@yellow;
    marker-width:@width*5;
    marker-line-width:@width;
    marker-line-opacity:@opacity*2;
    }
    ::highlight3 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*3;
    marker-line-color:@yellow;
    marker-width:@width*3;
    marker-line-width:@width;
    marker-line-opacity:@opacity*3;
    }
   marker-allow-overlap:true;
   marker-fill:lighten(@yellow,55%);
   marker-opacity:.4;
   marker-width:1;
   marker-line-color:#ffffff;
  }
  
  [zoom >= 5] {
    marker-allow-overlap:true;
  ::highlight{
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*1;
    marker-line-color:@yellow;
    marker-width:@width*6;
    marker-line-width:@width;
    marker-line-opacity:@opacity*1;
    }
    ::highlight2 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*2;
    marker-line-color:@yellow;
    marker-width:@width*4;
    marker-line-width:@width;
    marker-line-opacity:@opacity*2;
    }
    ::highlight3 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*3;
    marker-line-color:@yellow;
    marker-width:@width*2;
    marker-line-width:@width;
    marker-line-opacity:@opacity*3;
    }
   marker-allow-overlap:true;
   marker-fill:lighten(@yellow,55%);
   marker-opacity:.4;
   marker-width:.5;
   marker-line-color:#ffffff;
  }
  [zoom > 6] {
    marker-allow-overlap:true;
  ::highlight{
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*1;
    marker-line-color:@yellow;
    marker-width:@width*7;
    marker-line-width:@width;
    marker-line-opacity:@opacity*1;
    }
    ::highlight2 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*2;
    marker-line-color:@yellow;
    marker-width:@width*5;
    marker-line-width:@width;
    marker-line-opacity:@opacity*2;
    }
    ::highlight3 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*3;
    marker-line-color:@yellow;
    marker-width:@width*3;
    marker-line-width:@width;
    marker-line-opacity:@opacity*3;
    }
   marker-allow-overlap:true;
   marker-fill:lighten(@yellow,55%);
   marker-opacity:.4;
   marker-width:1;
   marker-line-color:#ffffff;
  }
  [zoom >= 8] {

  ::highlight {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*1;
    marker-line-color:@yellow;
    marker-width:@width*7;
    marker-line-width:@width;
    marker-line-opacity:@opacity*1;
    }
    ::highlight2 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*2;
    marker-line-color:@yellow;
    marker-width:@width*5;
    marker-line-width:@width;
    marker-line-opacity:@opacity*2;
    }
  ::highlight3 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*3;
    marker-line-color:@yellow;
    marker-width:@width*3;
    marker-line-width:@width;
    marker-line-opacity:@opacity*3;
      }
   marker-allow-overlap:true;
   marker-fill:lighten(@yellow,55%);
   marker-opacity:.4;
   marker-width:1;
   marker-line-color:#ffffff;
    ::again {
      marker-width:1;
      marker-fill:white;
      marker-opacity:1;
      }
    }

  [zoom >= 11] {
  ::highlight {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*1;
    marker-line-color:@yellow;
    marker-width:@width*11;
    marker-line-width:@width*11;
    marker-line-opacity:0;
    }
    ::highlight2 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*2;
    marker-line-color:@yellow;
    marker-width:@width*7;
    marker-line-width:@width*7;
    marker-line-opacity:0;
    }
  ::highlight3 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*3;
    marker-line-color:@yellow;
    marker-width:@width*4;
    marker-line-width:@width*4;
    marker-line-opacity:0;
      }
   marker-allow-overlap:true;
   marker-fill:lighten(@yellow,55%);
   marker-opacity:.8;
   marker-width:2;
   marker-line-color:transparent;
    ::again {
      marker-width:1;
      marker-fill:white;
      marker-opacity:1;
      }
    }
     /* - - - - - - - - new stuff  - - - - - - - - - - */  
 /* [zoom >= 8] {
     ::shadow {
        marker-width:14;
        marker-fill:black;
        marker-opacity:.05;
        marker-line-opacity:0;
        marker-line-color:black;
        marker-allow-overlap:true;
        }
      ::whitelight {
      marker-width:7;//@width*8;
      marker-fill:white;//lighten(@yellow,60%);
      marker-opacity:1;//.4;
      marker-line-opacity:0;
      marker-line-color:white;
      marker-allow-overlap:true;
      
        }
  ::highlight {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*1;
    marker-line-color:@yellow;
    marker-width:@width*7;
    marker-line-width:@width;
    marker-line-opacity:@opacity*1;
    }  
    ::highlight2 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*2;
    marker-line-color:@yellow;
    marker-width:@width*5;
    marker-line-width:@width;
    marker-line-opacity:@opacity*2;
    }
  ::highlight3 {
    marker-line-color:@yellow;
    marker-allow-overlap:true;
    marker-fill:@yellow;
    marker-opacity:@opacity*3;
    marker-line-color:@yellow;
    marker-width:@width*3;
    marker-line-width:@width;
    marker-line-opacity:@opacity*3;
      }
   marker-allow-overlap:true;
   marker-fill:lighten(@yellow,55%);
   marker-opacity:.4;
   marker-width:1;
   marker-line-color:#ffffff;
    ::again {
      marker-width:1;
      marker-fill:white;
      marker-opacity:1;
      }
    }*/
}

/*#delauney  [zoom <= 8] {
  line-color:lighten(@yellow,20%);//#E95C40;
  line-width:0.2;
  line-opacity:.3;
  polygon-opacity:0;
  polygon-fill:transparent;
}*/
