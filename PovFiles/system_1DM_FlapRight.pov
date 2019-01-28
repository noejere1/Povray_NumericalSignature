
#include "colors.inc"

#include "../includes/cameras.inc"
#include "../includes/objects.inc"
#include "../includes/lighting.inc"
#include "../includes/textures.inc"
#include "../includes/setup.inc"


#if(god_mode)
    //object{light_source_1_display}
    camera{camera_godMode}
#else
    camera{camera_1DM}
#end

#if(flap_lighting_mode)
    object{carton_flap_right}
    light_source{LS_Right}
#else
    light_source{LS_base}
#end






object
{   
    //places the image on the center of the camera view
    object{plane0}
    texture{datamatrix1}
    translate <0.5, 0.5, 0>   
                                                       
    rotate<current_x_rot, current_y_rot, 0>
    
    #debug concat(str(current_x_rot,5,2),"\n")
    #debug concat(str(current_y_rot,5,2),"\n") 
    
}


