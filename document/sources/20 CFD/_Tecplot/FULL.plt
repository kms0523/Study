TITLE = test
FILETYPE = FULL
VARIABLES = X,Y,U,V,W

ZONE
T = test_zone
ZONETYPE = FEQUADRILATERAL
NODES = 4 
ELEMENTS = 1 
VARLOCATION = 
DATAPACKING = BLOCK

# VARIABLE DATA
1 2 1 2 
1 1 2 2 
5 3 2 1
1 2 3 4
-1 2 3 4

# CONNECTIVITY
1 2 4 3

# VARLOCATION = ([3,5] = CELLCENTERED)
