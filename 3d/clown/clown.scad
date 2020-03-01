
prof_volto = 1.5;
dim_volto=100;

difference(){
viso();
occhi();
}
module viso(){

minkowski(){
    hull(){
                
            translate([-dim_volto/20,dim_volto/2,0]) cube(prof_volto);
        
            translate([dim_volto/5,0,0]) cube(prof_volto);
                
            translate([dim_volto,dim_volto,0]) cube(prof_volto);

            translate([dim_volto/5,dim_volto,0]) cube(prof_volto);

            translate([dim_volto,0,0]) cube(prof_volto);
    }
cylinder(10);
}
}



module occhi(){
    
  //translate([dim_volto/5*4, dim_volto/5,0])  sphere(r=5);
    translate([dim_volto/5*4, dim_volto/5,2])  sphere(d=25,$fn=100);
}