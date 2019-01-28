

#include "colors.inc"

#include "../includes/cameras.inc"
#include "../includes/objects.inc"
#include "../includes/lighting.inc"
#include "../includes/textures.inc"
#include "../includes/setup.inc"




#if(god_mode)
    object{light_source_1_display}
    object{light_source_2_display}
    object{light_source_3_display}
    object{light_source_4_display}
    camera{camera_godMode}
#else
    camera{camera_MAS}
#end



light_source{LS1}
light_source{LS2}
light_source{LS3}
light_source{LS4}
    
object{carton_flap_left}
object{carton_flap_right}

object
{   
    //places the image on the center of the camera view
    object{plane0}
    texture{datamatrix1}
    translate <0.5, 0.5, 0>   
                                                       
    //rotate<current_x_rot, current_y_rot, 0> 
    
}



