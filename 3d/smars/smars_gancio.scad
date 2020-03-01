union(){
    translate([-20,0,0]) chassis_gancio();
translate([0,4,0]) gancio();
}


module gancio(){
difference(){
    import("/home/diomedem/Documenti/3d/arduino/smars/SMARS_Trailer_and_new_larger_frame/files/Attache_chassis.stl", center=true);
   cube([50,7,20],center= true);

}
}


module chassis_gancio(){
    difference(){
        chassis();
  translate([0,5.9,0])  cube([40,13,12]);
    }
    
}




module chassis(){

union (){
  
  translate([20,-31,-15]){
        import("/home/diomedem/Documenti/3d/arduino/smars/SMARS_modular_robot/files/connector_a.stl");
  }
  cube([38,5,10.5]);
}
}