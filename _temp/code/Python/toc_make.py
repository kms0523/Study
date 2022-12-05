import os
import sys

# folder_path = sys.argv[1]
# toc_file = sys.argv[2]

# if not os.path.isdir(folder_path):
#     print(folder_path,"is not valid folder path")
#     exit()

folder_path = "C:/midas/code/MecSolverTheoryDocument/sources/"
toc_file = "_toc.yml"


## foler 내에서 search 해서, 모든 mark down 파일 찾기 (but _build안에 폴더는 제외..)
file_paths = []
for (root, directories, files) in os.walk(folder_path):
    for file in files:
        if '_build' not in root:
            if '.md' in file:
                file_path = os.path.join(root, file)
                file_path = file_path.replace(folder_path, '')
                file_path = file_path.replace('.md', '')
                file_path = file_path.split('\\')
                file_paths.append(file_path)

## file name 별로 sort, remove, relocation
file_paths.sort()

remove_names = ['index']
if remove_names in file_paths:
    file_paths.remove(remove_names)

relocation_names = ['references']
if relocation_names in file_paths:
    file_paths.remove(relocation_names)
    file_paths.append(relocation_names)

# for file_path in file_paths:
#     print(file_path)


## write toc file
file = open(folder_path+toc_file, 'w')

file.write('# Table of contents'+'\n')
file.write('# Learn more at https://jupyterbook.org/customize/toc.html'+'\n')
file.write('\n')
file.write('format: jb-book'+'\n')
file.write('root: index'+'\n')
file.write("parts:"+"\n")




file.write('chapters:'+'\n')

file_dir_old = ''
file.write_section = True
for file_path in file_paths:
    if file_path[0] != file_dir_old:
        file.write('- file: '+'/'.join(file_path)+'\n' )
        file.write_section = True
    else :
        if file.write_section : 
            file.write('  sections:'+'\n')
            file.write_section = False
        file.write('    - file: '+'/'.join(file_path) +'\n')
    file_dir_old = file_path[0]
file.close()