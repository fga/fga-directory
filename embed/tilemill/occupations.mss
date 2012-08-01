@brown:#ACA68a;
@background:lighten(desaturate(@brown, 20%),20%);
@yellow:#ffcc00;
@white:#ffffff;
@opacity:.1;
@width:1;

Map {
  background-color:darken(@background,55%);//spin(desaturate(darken(#205791,5%),25%),90);
  }

#stateslakes {
  line-width:1;
  line-color:darken(@background,60%);
  line-join: round;  
  polygon-fill:darken(@background,60%);
  polygon-opacity: 1;
}

#occupations {
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
}

#delauney {
  line-color:lighten(@yellow,20%);//#E95C40;
  line-width:0.2;
  line-opacity:.3;
  polygon-opacity:0;
  polygon-fill:transparent;
}