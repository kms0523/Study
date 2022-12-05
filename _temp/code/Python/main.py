import os
from mslib import mspath

path = "Test/"
# print(mspath.extract_target_extension_filenames('.txt',path))
name_extension_tuples = mspath.extract_name_extension_tuples(path)
name_extension_tuples.remove(('B',''))

print(name_extension_tuples)
