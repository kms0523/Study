import os
import pathlib 
import error as mserror

def check_path_format(path):
	if not path.endswith('/'):
		mserror.error_invalid_input('"' + path + '" is not vaild path format. path should be ended with /')

def check_path_existence(path):
	if not os.path.isdir(path):	
		mserror.error_invalid_input('"' + path + '" is not exist')

def extract_foldernames(path='./'):
	check_path_format(path)
	check_path_existence(path)

	name_lists = os.listdir(path)
	
	folder_names = []
	for name in name_lists:
		if os.path.isdir(path + name + '/'):
			folder_names.append(name)
				
	return folder_names

def extract_foldernames_filenames(path='./'):	
	check_path_format(path)
	check_path_existence(path)

	name_lists = os.listdir(path)

	foldernames = []
	filenames = []

	for name in name_lists:
		if os.path.isdir(path + name + '/'):
			foldernames.append(name)
		else:
			filename = remove_filename_extension(name)
			filenames.append(filename)
				
	return [foldernames, filenames]

def remove_filename_extension(filename):
	return pathlib.Path(filename).stem

def parent_path(path):
	check_path_format(path)
	
	return (pathlib.Path(path).parent)

def root_path(path):
	check_path_format(path)

	return path.split('/')[0]

def current_folder_name(path):
	check_path_format(path)
	
	return path.split('/')[-2]