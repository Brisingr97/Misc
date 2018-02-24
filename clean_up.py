import os
import sys
default_path = "./../Desktop" 
def reverse(s):
    flag = 0
    to_rev = ""
    for i in s:
        if (flag==1):
            to_rev = to_rev + i
        if (i=='.'):
            to_rev = ""
            flag = 1
    return to_rev
    
def put_in_folder(directory,file):
    # find folder
    extension_name = reverse(file)
    new_path = directory+extension_name+"/"
    if not os.path.exists(new_path):
        os.makedirs(new_path)
        print(directory+file,new_path+file)
    os.rename(directory+file,new_path+file)

# def find_big_files(location):
#     file_names =[]
#     # if this is a folder, then enter and save names of big files
#     for file in os.listdir(location):
#         if  os.stat(file).st_size>max_size:
#             max_size = os.stat(file).st_size
            
#         if os.path.isdir(file):
    
        
        
#     return file_names

def iterate_through_files():
    directory = input("Folder to clean up? Press Enter for this folder ")
    if directory=="":
        directory = "./"
    # big_files = find_big_files(directory)
    for filename in os.listdir(directory):
        if(filename!="clean_up.py" and filename[-4:]!=".lnk"):
            try:
                put_in_folder((directory+"/"),filename)
            except Exception:
                pass
mode = int(input("Run in mode? "))

if mode==1:
    iterate_through_files()
        