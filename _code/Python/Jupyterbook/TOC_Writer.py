from .mslib import mspath

class TOC_Writer:
	def write(self, source_folder_path) -> None:
		mspath.check_path_format(source_folder_path)
		mspath.check_path_existence(source_folder_path)		

		toc_file_path = '_toc.yml'		
		file = open(toc_file_path, 'w')

		self.__write_header(file)

		names = mspath.extract_foldernames(source_folder_path)

		# Documents
		for name in names:			
			if name.startswith('_'): #convetion
				continue

			chapter_folder_path = source_folder_path + name + '/'
			self.__write_chapter(file, chapter_folder_path)

		file.close()



	def __init__(self) -> None:
		pass



	def __write_header(self, file) -> None:
		file.write( '# Table of contents'+'\n'
					+ '# Learn more at https://jupyterbook.org/customize/toc.html'+'\n\n'
					+ 'format: jb-book'+'\n'
					+ 'root: sources/cover'+'\n'
					+ "parts:"+"\n")




	def __write_chapter(self, file, current_path):
		mspath.check_path_format(current_path)
		mspath.check_path_existence(current_path)

		indent = '  '
		caption = mspath.current_folder_name(current_path)[3:] #convention
		file.write(indent + '- caption: \'' + caption + '\'\n')
		
		name_extension_tuples = mspath.extract_name_extension_tuples(current_path)

		#Processing documents
		indent = indent + '  '
		file.write(indent + 'chapters: ' + '\n')

		self.__write_in_TOC_format(file, indent,current_path, name_extension_tuples)



	def __write_section(self, file, indent, current_path):
		mspath.check_path_format(current_path)
		mspath.check_path_existence(current_path)

		name_extension_tuples = mspath.extract_name_extension_tuples(current_path)
		
		# Processing main document
		main_file_name = mspath.current_folder_name(current_path)[3:] #convention
		main_file_path = current_path + main_file_name
		self.__write_file(file, indent, main_file_path)
		
		name_extension_tuples.remove((main_file_name, '.md'))

		# Processing other documents
		indent = indent + '  '
		file.write(indent + 'sections: \n')

		self.__write_in_TOC_format(file, indent,current_path, name_extension_tuples)





	def __write_file(self, file, indent, path) -> None:
		file.write(indent + '- file: ' + path + '\n')





	def __write_in_TOC_format(self, file, indent, current_path, name_extension_tuples) -> None:
		for [name, extension] in name_extension_tuples:
			if name.startswith('_'): #convetion
				continue

			if extension == '':
				section_folder_path = current_path + name + '/'
				self.__write_section(file, indent, section_folder_path)
			elif extension == '.md':
				path = current_path + name				
				self.__write_file(file,indent,path)	






	def __relative_path(self, path) :
		return path[self.source_folder_len:]		