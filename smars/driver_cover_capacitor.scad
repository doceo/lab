difference(){
posix_holder();
translate([14.2,-23.5,0])capacitor();
}
module posix_holder(){
 translate([-26,6,56])   rotate([90,0,0]) import("/home/diomedem/Documenti/3d/arduino/smars/SMARS_QUAD_MOD/files/servo_driver_cover.stl");
    
}

module capacitor(){
cylinder(r=4.5, h=14, $fn=80);
}
