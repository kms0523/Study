from .API import mspath

# section 이름과 동일한 .md 파일이 main section 파일이 된다.
# TOC 파일에 적힌 순서대로 toc가 생성되는지 아니면 .md파일의 H1의 알파벳 순서로 toc가 생성되는지 확인해보기

class TOC_Writer:
	def __init__(self) -> None:
		pass


	def write(self, soruce_folder_path) -> None:
		mspath.check_path_format(soruce_folder_path)
		mspath.check_path_existence(soruce_folder_path)
		
		self.source_folder_len = len(soruce_folder_path)

		toc_file_path = soruce_folder_path + '__toc.yml'
		file = open(toc_file_path, 'w')

		file.write( '# Table of contents'+'\n'
							+ '# Learn more at https://jupyterbook.org/customize/toc.html'+'\n\n'
							+ 'format: jb-book'+'\n'
							+ 'root: cover'+'\n'
							+ "parts:"+"\n")

		folder_names = mspath.extract_foldernames(soruce_folder_path)

		for folder_name in folder_names:
			chapter_folder_path = soruce_folder_path + folder_name + '/'
			self.__write_chapter(file, chapter_folder_path)

		file.close()



	def __write_chapter(self, file, current_path):
		mspath.check_path_format(current_path)
		mspath.check_path_existence(current_path)

		indent = '  '
		caption = mspath.current_folder_name(current_path) #convention
		file.write(indent + '- caption: ' + caption + '\n')
		
		indent = indent + '  '
		file.write(indent + 'chapters: ' + '\n')
				
		[folder_names, file_names] = mspath.extract_foldernames_filenames(current_path)

		for folder_name in folder_names:
			section_folder_path = current_path + folder_name + '/'
			self.__write_section(file, indent, section_folder_path)

		self.__write_file(file,indent,file_names,current_path)



	def __write_section(self, file, indent, current_path):
		[folder_names, file_names] = mspath.extract_foldernames_filenames(current_path)

		# Processing Main Document
		main_file_name = mspath.current_folder_name(current_path) #convention
		relative_path = self.__relative_path(current_path)
		file.write(indent + '- file: ' + relative_path + main_file_name + '\n')
		
		file_names.remove(main_file_name)

		# Processing other documents
		indent = indent + '  '
		file.write(indent + 'sections: \n')

		for folder_name in folder_names:
			section_folder_path = current_path + folder_name + '/'
			self.__write_section(file, indent, section_folder_path)

		self.__write_file(file,indent,file_names,current_path)



	def __write_file(self, file, indent, file_names, current_path) -> None:
		relative_path = self.__relative_path(current_path)
		for file_name in file_names:
			file.write(indent + '- file: ' + relative_path + file_name + '\n')



	def __relative_path(self, path) :
		return path[self.source_folder_len:]		