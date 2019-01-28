
#include "../includes/setup.inc"



//###################### Plane on which to apply the images ############
    
#declare plane0 = 
    plane
    {
        -z, 0
    } 
    
//#######################  Carton Flap Simulators #####################
    

    
#declare carton_flap_left = 
    box
    {        
        <-1.75, 4,-flaps_height>
        <-2.25, -4, flaps_height>
        texture
        {
            pigment{ color Black }
        }
        translate<0.75 * clock, 0, 0>
    }
    
#declare carton_flap_right = 
    box
    {        
        <1.75, 4,-flaps_height>
        <2.25, -4, flaps_height>
        texture
        {
            pigment{ color Black }
        }
        translate<-0.75 * clock, 0, 0>
    }
    
#declare carton_flap_top = 
    box
    {       
        <4, 1.75 ,-flaps_height>
        <-4, 2.25, flaps_height>
        texture
        {
            pigment{ color Black }
        }
        translate<0, -0.75 * clock, 0>
    }
    
#declare carton_flap_bottom = 
    box
    {
        <4, -1.75 ,-flaps_height>
        <-4, -2.25, flaps_height>
        texture
        {
            pigment{ color Black }
        }
        translate<0, 0.75 * clock, 0>
    }      
    
    

//###################### God mode diplays ############################    
    
#declare light_source_1_display =
    sphere
    {
        <-5, 0, -4.5>,0.5
        
        texture 
        {
            pigment { color Orange }
        }
        translate<5*clock,0,0>
    }
    
#declare light_source_2_display =
    sphere
    {
        <5, 0, -4.5>,0.5
        
        texture 
        {
            pigment { color Orange }
        }
        translate<-5*clock,0,0>
    }
    
#declare light_source_3_display =
    sphere
    {
        <-2.5, 0, -4.5>,0.5
        
        texture 
        {
            pigment { color Orange }
        }
        translate<5*clock,0,0>
    }
    
#declare light_source_4_display =
    sphere
    {
        <2.5, 0, -4.5>,0.5
        
        texture 
        {
            pigment { color Orange }
        }
        translate<-5*clock,0,0>
    }
    
#declare camera_1DM_display =
    box
    {   
        <-0.5, -0.5, -0.5>
        <0.5, 0.5, -1.5>
        texture 
        {
            pigment { color Blue }
        }
    }