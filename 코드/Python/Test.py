import os

explore_path = "Directory & File/"

for [path, folder_list, file_list] in os.walk(explore_path):
	print("path:",path,"\tfolders:",folder_list,"\tfile_list",file_list)

