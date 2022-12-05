import os
import pathlib 
from . import mserror

def check_path_format(path):
	if not path.endswith('/'):
		mserror.error_invalid_input('"' + path + '" is not vaild path format. path should be ended with /')

def check_path_existence(path):
	if not os.path.isdir(path):	
		mserror.error_invalid_input('"' + path + '" is not exist')

def extract_name_extension_tuples(path='./'):
	check_path_format(path)
	check_path_existence(path)

	name_lists = os.listdir(path)
	
	name_extension_tuples = []
	for name in name_lists:
		name_extension_tuples.append(os.path.splitext(name))
				
	return name_extension_tuples


def extract_names(path='./'):
	names = os.listdir(path)
	for i in range(len(names)):
		names[i] = remove_filename_extension(names[i])
	return names

def extract_foldernames(path='./'):
	check_path_format(path)
	check_path_existence(path)

	name_lists = os.listdir(path)
	
	folder_names = []
	for name in name_lists:
		if os.path.isdir(path + name + '/'):
			folder_names.append(name)
				
	return folder_names

def extract_target_extension_filenames(target_extension, path='./'):
	check_path_format(path)
	check_path_existence(path)

	name_lists = os.listdir(path)
	
	file_names = []
	for name in name_lists:
		[splited_name, extension] = os.path.splitext(name)
		
		if extension == target_extension:
			file_names.append(splited_name)
				
	return file_names
	

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

def is_folder(path):	
	return os.path.isdir(path)

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