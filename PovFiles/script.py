import os
import subprocess

executable_path = "C:\\Program Files\\POV-Ray\\v3.7\\bin\\"
pov_file_path ="C:\\povray\\Numerical_Signature\\PovFiles\\"

input_files_path = "C:\\povray\\Numerical_Signature\\input_images\\"
output_files_path = "C:\\povray\\Numerical_Signature\\output_images\\"
angles_file_path = output_files_path + "angles.out"

ini_file_path = pov_file_path + "image_generator.ini"

flap_setups = ["system_1DM_FlapLeft.pov","system_1DM_FlapTop.pov","system_1DM_FlapRight.pov","system_1DM_FlapBottom.pov","system_1DM_NoFlap.pov"]



 
def get_input_images(input_files_path):
    return os.listdir(input_files_path)


def generate_image_variations(image):
    #setup files for povray execution
    ini_file_name, extension = os.path.splitext(image)

    for flap in flap_setups:
        set_ini_file(ini_file_name, flap)
        set_texture_include_file(image)

        #call povray execute in cmd
        os.chdir(executable_path)
        subprocess.call(["pvengine.exe","/EXIT", "/RENDER", ini_file_path])
        

def set_ini_file(file_name, flap_setup):
    with open(ini_file_path, 'r') as file:
        data = file.readlines()

    flap_string = flap_setup[11:-4]
    print(flap_string)
    data[0] = 'Input_File_Name = ' + flap_setup + '\n'
    data[5] = 'Output_File_Name = "'+ output_files_path + file_name + "-" + flap_string + '"\n'
    
    with open(ini_file_path, 'w') as file:
        file.writelines( data )
    return 

def set_texture_include_file(file_name):
    include_file_path = pov_file_path + "..\\includes\\textures.inc"
    with open(include_file_path, 'r') as file:
        data = file.readlines()

    data[6] = '            png "../input_images/'+ file_name + '"\n'
    
    with open(include_file_path, 'w') as file:
        file.writelines( data )
    return




    
def rename_files_by_angle(output_files_path):
    rotation_angles = extractAngles(angles_file_path)

    for file in os.listdir(output_files_path):
        file_name, ext = os.path.splitext(file)
        
        if ext == ".png":
            file_number = int(file_name[-3:])
            
            print (file_number)
            new_file_name = file_name + rotation_angles[file_number] + ext
            os.rename(output_files_path + file, output_files_path + new_file_name)
            

def extractAngles(angles_file_path):
    angles = {}
    with open(angles_file_path, 'r') as file:
        data = file.readlines()

    next_angle = 1
    for i in range(0,len(data)-1):
        if(i%2 == 0):
            angles[next_angle] = data[i][:-2] + "_" + data[i+1][:-2]
            next_angle += 1
    print(angles)
    return angles
        
    
    


def main():

    #get all image names in input file
    image_list = get_input_images(input_files_path)
    print(image_list)

    #clear output directory
    filelist = [ f for f in os.listdir(output_files_path)]
    for f in filelist:
        os.remove(os.path.join(output_files_path, f))

    for image in image_list:
        generate_image_variations(image)

    rename_files_by_angle(output_files_path)
    
    pass
 
if __name__ == "__main__":
    main()
