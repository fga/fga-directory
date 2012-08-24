/* Occupations as imported from a CSV export of http://directory.occupy.net */

#markers {
    marker-allow-overlap:true;
}
.occupations {
  marker-opacity:1;
  marker-file:url(assets/marker-mid.svg);
  marker-transform:"scale(.25)";
  
  [zoom>=0]{     marker-transform:"scale(0.25)";  }
  [zoom>=3]{     marker-transform:"scale(0.40)";  }
  [zoom>=5]{     marker-transform:"scale(0.50)";  }  
  [zoom=6]{      marker-transform:"scale(0.70)";  }  
  [zoom=7]{      marker-transform:"scale(0.85)";  }  
  [zoom>=8]{
    marker-file:url(assets/marker-closeup3.svg);
  }
  [zoom=8]{      marker-transform:"scale(0.45)";  }
  [zoom=9]{      marker-transform:"scale(0.60)";   }
  [zoom=10]{     marker-transform:"scale(0.80)";   }
  [zoom=11]{     marker-transform:"scale(1.00)";    }
  [zoom>=12]{    marker-transform:"scale(1.40)";  }
  
}
