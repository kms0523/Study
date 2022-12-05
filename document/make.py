import sys
import os
import shutil

from _toc.TOC_Writer import TOC_Writer

writer = TOC_Writer()
writer.write('sources/')

if __name__ == "__main__":
    if sys.argv[1] == "build":
        os.system("jb build ./")

    elif sys.argv[1] == "clean":
        if os.path.exists("./_build"):
            shutil.rmtree("./_build")

    elif sys.argv[1] == "rebuild":
        if os.path.exists("./_build"):
            shutil.rmtree("./_build")
        os.system("jb build ./")
