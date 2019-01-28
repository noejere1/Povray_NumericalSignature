//light sources on the setup (not physical values)

    
#declare LS_Left = 
    light_source 
    {       
        <-2.5, 0, -(flaps_height + 1.5)> color White
        area_light <0,0.25,0>,<0,0,0.25>,5,5
        adaptive 1
        jitter
        translate<0.75*clock, 0, 0>
    }
      
#declare LS_Right = 
    light_source 
    {   
        <2.5, 0, -(flaps_height + 1.5)> color White
        area_light <0,0.25,0>,<0,0,0.25>,5,5
        adaptive 1
        jitter
        translate<-0.75*clock, 0, 0>
    }
    
#declare LS_Top = 
    light_source 
    {   
        <0, 2.5, -(flaps_height + 1.5)> color White
        area_light <0.25,0,0>,<0,0,0.25>,5,5
        adaptive 1
        jitter
        translate<0, -0.75*clock, 0>
    }
    
#declare LS_Bottom = 
    light_source 
    { 
        <0, -2.5, -(flaps_height + 1.5)> color White
        area_light <0.25,0,0>,<0,0,0.25>,5,5
        adaptive 1
        jitter
        translate<0, 0.75*clock, 0>
    }
