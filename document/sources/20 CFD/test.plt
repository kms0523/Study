TITLE = test
FILETYPE = FULL
VARIABLES = X, P

ZONE
T = test_zone
ZONETYPE = FELINESEG
NODES = 3
ELEMENTS = 2
VARLOCATION = ([2] = CELLCENTERED)
DATAPACKING = BLOCK

# VARIABLE DATA
1.0e06 2.0e06 3.0e06
8.1324E06 3.1324E06 

# CONNECTIVITY
1 2
2 3

# VARLOCATION = ([2] = CELLCENTERED)
# VARLOCATION = (NODAL)

#  FVM을 연속된 값으로 post하기 위해서는 중복 post point가 없어야 됨
#  이 경우에는 grid file에 있는 connectivity를 그대로 활용하는 방식으로 진행하되
#   subcell로 쪼개서 post하는 기능을 막아야 된다.

#  그 외에는
#  FVM을 discrete한 값으로 post하기 위해서는 중복 post point가 있어야 됨
#  FVM 내부의 slope까지 post하기 위해서는 중복 post point가 있어야 됨
#  현재처럼 cell마다 post point를 만들어서 경계에는 중복된 post point가 생기게 한다.
#  메모리를 아끼기 위해서는 실제로 node를 넘기는게 아니라 node의 shared point를 넘기게 해서
#  경계면에서 공유하는 node에 대한 중복 생성을 방지할 수 있다. 근데 shared point가 메모리를 얼마나 먹지?
#  메모리 사용량을 확인하는 코드