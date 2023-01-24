import sys

def error_invalid_input(message) -> None:
	error_location = sys._getframe(2).f_code.co_name + ' in ' + sys._getframe(3).f_code.co_name
	
	print('Error location:\t', error_location)
	print('Error name:\t invalid input')
	print('Message:\t ' + message)
	exit()






# def remove_filename_extension(filename):
# 	parsed_filename = filename.split('.')

# 	if len(parsed_filename) != 2:
# 		
# 		
# 		
# 		
# 		

# 	return filename.split('.')[0]




# # print(remove_filename_extension("test"))