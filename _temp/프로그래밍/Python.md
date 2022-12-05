# 기본 문법
[import OO와 from OO import*의 차이 - 코딩유치원](https://coding-kindergarten.tistory.com/73)  
[여러 경로의 모듈 import](https://cuorej.tistory.com/entry/PYTHON-%EC%97%AC%EB%9F%AC-%EA%B2%BD%EB%A1%9C%EC%9D%98-%EB%AA%A8%EB%93%88-import-%ED%95%98%EA%B8%B0-1)

## Numpy

### slicing
``` python
# B = A[9,11,:] X
C = A[[9,11],:]
D = A[(9,11),:]
E = A[9:12, :]  # begin:end = [begin,end)
```

### rank
``` python
numpy.linalg.matrix_rank(A)
```
# Conda
[https://projecteli.tistory.com/171](https://projecteli.tistory.com/171)

# Jupyter
Anaconda Powershell Prompt 실행 >> jupyter notebook 입력

# Sympy 사용법
[Sympy 사용법 - allman 블로그](http://allman84.blogspot.com/2018/10/sympy.html)

# 문제해결

## 문제1
첫번째 디버그는 되는데 두번째 디버그부터 지정된 경로를 찾지 못하는 문제

경로에 띄어쓰기와 특수문자가 들어간 경우 문제가 발생

* 2004 (Lee & Bathe) X
* 2004 (Lee&Bathe) X
* 2004_(Lee_&_Bathe)O
* 2004(Lee&Bathe) O
* 2004 (Lee Bathe) O
