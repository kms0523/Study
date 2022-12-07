from .mslib import mspath

# section 이름과 동일한 .md 파일이 main section 파일이 된다.
# TOC 파일에 적힌 순서대로 toc가 생성

class TOC_Writer:
	def __init__(self) -> None:
		pass


	def write(self, source_folder_path) -> None:
		mspath.check_path_format(source_folder_path)
		mspath.check_path_existence(source_folder_path)		

		toc_file_path = '_toc.yml'		
		file = open(toc_file_path, 'w')

		self.__write_header(file)

		names = mspath.extract_names(source_folder_path)

		for name in names:			
			if name.startswith('_'): #convetion
				continue

			path = source_folder_path + name
			if mspath.is_folder(path):
				chapter_folder_path = source_folder_path + name + '/'
				self.__write_chapter(file, chapter_folder_path)

		file.close()



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
		caption = mspath.current_folder_name(current_path) #convention
		file.write(indent + '- caption: \'' + caption + '\'\n')
		
		indent = indent + '  '
		file.write(indent + 'chapters: ' + '\n')
				
		names = mspath.extract_names(current_path)

		for name in names:
			if name.startswith('_'): #convetion
				continue

			path = current_path + name			
			if mspath.is_folder(path):
				section_folder_path = path + '/'
				self.__write_section(file, indent, section_folder_path)
			else:
				self.__write_file(file,indent,path)



	def __write_section(self, file, indent, current_path):
		names = mspath.extract_names(current_path)

		# Processing Main Document
		main_file_name = mspath.current_folder_name(current_path) #convention
		main_file_path = current_path + main_file_name
		self.__write_file(file, indent, main_file_path)
		
		names.remove(main_file_name)

		# Processing other documents
		indent = indent + '  '
		file.write(indent + 'sections: \n')

		for name in names:
			if name.startswith('_'): #convetion
				continue

			path = current_path + name			
			if mspath.is_folder(path):
				section_folder_path = path + '/'
				self.__write_section(file, indent, section_folder_path)
			else:
				self.__write_file(file,indent,path)



	def __write_file(self, file, indent, path) -> None:
		file.write(indent + '- file: ' + path + '\n')


	def __relative_path(self, path) :
		return path[self.source_folder_len:]		