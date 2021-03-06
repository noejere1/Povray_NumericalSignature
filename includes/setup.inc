


//############################### parameters to set #######################################

//TO SET: max/min angles
#declare maximum_perspective_angle = 5;
#declare minimum_perspective_angle = -5;

#declare flaps_height = 3;

#declare god_mode = false;

#declare flap_lighting_mode = true;


//############################### Automatic calculations ##################################


#declare angle_variation = maximum_perspective_angle - minimum_perspective_angle + 1;

#declare clock_iteration = final_clock / sqrt(final_frame);


#declare x_ratio = mod(clock,clock_iteration) * sqrt(final_frame);
#declare y_ratio = floor(clock / clock_iteration) / sqrt(final_frame);

#declare current_x_rot = floor(min(minimum_perspective_angle + (x_ratio * angle_variation), maximum_perspective_angle));
#declare current_y_rot = min(minimum_perspective_angle + (y_ratio * angle_variation), maximum_perspective_angle);