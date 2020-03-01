braccio_h = 3.5;
braccio_l = 3.5;
braccio_p = 2;

$fn=100;


3_point();
rotate([0,45,0])translate([2,3.25,3.25]){ braccio();
}




module 3_point(){
    union()  {
        angolo();
        translate ([-5,0,0])cube(5,2,5);
      }

}


module angolo(){

        difference(){

            import("4_Point_Connector.stl");
            translate([-17,-17,0]) cube(17);
        }

 }
 
 
 
module braccio(){
difference(){
cube([20,6.5,6.5], center=true);
cube([20,3.2,3.2], center=true);
}
}