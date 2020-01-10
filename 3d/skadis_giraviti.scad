



difference(){
base();
 giraviti();
}


module giraviti(){
    for(y=[20:15:80]){
        for(x=[8:15:40]){
            translate([x,y,0])    
            cylinder(d = 8, h = 12, fn=100);
        }
    }
}


module base(){
   
        union(){
                        import( "/home/diomedem/Documenti/3d/ikea/skadis/skadis_holder_/files/skadis_1_giravite.stl");
                      
                translate([0,10,0]) cube([45,65,12 ]);    
        }

}
