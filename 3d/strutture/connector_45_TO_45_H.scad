
braccio_l = 3;


$fn=100;

hull(){
//for(x=[0:1:45]){
    rotate(x,0,0) braccio();
    
//}
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
cube([braccio_l,6.5,6.5], center=true);
cube([braccio_l,3.2,3.2], center=true);
}
}