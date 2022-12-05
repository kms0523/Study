import numpy as np
import pandas as pd

import linear_interpolation_api as lin_interpolation

#read data
filename = "GeometricNonlinearStatic14.xlsx"
sheetname = "14 fea"
header_line = 4
cols = "A:D"
nfx = pd.read_excel(
    filename, 
    sheet_name=sheetname, 
    header= header_line, 
    usecols=cols
    )

data_nfx = pd.DataFrame.to_numpy(nfx)

xs = data_nfx[:,0]
ys = data_nfx[:,1]
interpolation_xs = data_nfx[:,2]

xs = xs[np.isfinite(xs)]
ys = ys[np.isfinite(ys)]
interpolation_xs = interpolation_xs[np.isfinite(interpolation_xs)]

# interpolate
interpolation_ys = lin_interpolation.cal_interpolation_ys(xs,ys,interpolation_xs)

# write data
file_mode = 'a'         #append
sheet_mode = 'overlay'  #append
excel_writer = pd.ExcelWriter(filename, mode=file_mode, if_sheet_exists=sheet_mode)

df = pd.DataFrame(interpolation_ys)

start_row_index = 5
start_col_index = 6
write_sheet_name = sheetname
df.to_excel(
    excel_writer, 
    sheet_name=write_sheet_name, 
    header= False,
    index = False,
    startrow= start_row_index, 
    startcol= start_col_index
    )

excel_writer.close()



