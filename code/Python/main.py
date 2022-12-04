# import os,sys
# print(__file__)
# print(os.path.dirname(__file__))
# print(os.path.abspath(os.path.dirname(__file__)))
# print(os.path.dirname(os.path.abspath(os.path.dirname(__file__))))

from Jupyterbook.TOC_Writer import TOC_Writer

writer = TOC_Writer()
writer.write('Jupyterbook/test/')