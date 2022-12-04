import pandas as pd
import numpy as np

filename = "test.xlsx"
file_mode = 'a'         #append
sheet_mode = 'overlay'  #append
excel_writer = pd.ExcelWriter(filename, mode=file_mode, if_sheet_exists=sheet_mode)

data1 = np.random.rand(1,10)
data2 = np.random.rand(10,1)
data3 = np.random.rand(10)
df1 = pd.DataFrame(data1)
df2 = pd.DataFrame(data2)
df3 = pd.DataFrame(data3)



start_row_index = 1
start_col_index = 1
write_sheet_name = "test2"
df1.to_excel(
    excel_writer, 
    sheet_name=write_sheet_name, 
    header= False,
    index = False,
    startrow= start_row_index, 
    startcol= start_col_index
    )

start_row_index = 3
start_col_index = 3
write_sheet_name = "test2"
df2.to_excel(
    excel_writer, 
    sheet_name=write_sheet_name, 
    header= False,
    index = False,
    startrow= start_row_index, 
    startcol= start_col_index
    )

start_row_index = 5
start_col_index = 5
write_sheet_name = "test2"
df3.to_excel(
    excel_writer, 
    sheet_name=write_sheet_name, 
    header= False,
    index = False,
    startrow= start_row_index, 
    startcol= start_col_index
    )


excel_writer.close()



# (to_excel 옵션)[https://wikidocs.net/159484]
# (excelwirter 옵션)[https://pandas.pydata.org/docs/reference/api/pandas.ExcelWriter.html]
