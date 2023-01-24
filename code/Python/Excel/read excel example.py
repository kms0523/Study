import pandas as pd

filename = "test.xlsx"
header_line = 6
cols = "C:D"

nfx = pd.read_excel(filename, sheet_name="Sheet1", header= header_line, usecols=cols)
data_nfx = pd.DataFrame.to_numpy(nfx)

print(data_nfx)




# (read_excel 옵션 정리)[https://velog.io/@inhwa1025/Python-pandas%EC%9D%98-readexcel-%EC%98%B5%EC%85%98-%EC%A0%95%EB%A6%AC]