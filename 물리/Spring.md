# Equilibrium Equation
<p align = "center">
<img src = "./image/spring2.png">
</p>

위 그림과 같이 외력 $f_1,f_2$를 받아 변위 $d_1,d_2$가 생긴 `탄성 스프링(elastic spring)`이 평형상태에 있다고 하자.

왼쪽 물체에 대한 `힘 평형 방정식(force equilibrium equation)`은 다음과 같다.
$$ f_1 - k(d_1-d_2) = 0 $$

왼쪽 물체에 대한 force equilibrium equation은 다음과 같다.
$$ f_2 - k(d_2-d_1) = 0 $$

전체 force equilibrium equation을 행렬형태로 나타내면 다음과 같다.
$$ k\begin{bmatrix} 1 & -1 \\ -1 & 1 \end{bmatrix} \begin{bmatrix} d_1 \\ d_2 \end{bmatrix} = \begin{bmatrix} f_1 \\ f_2 \end{bmatrix} $$

# Discrete System Mathematical Model
## 1.System idealization
## 2.Element equilibrium  
   Element마다 state variable에 대한 equilibrium equation을 세운다.
## 3.Element assemblage
## 4.Calculation of response

# Linear Spring System

## 1. System idealization
<p align = "center">
<img src = "./image/spring1.png">
</p>

위 그림과 같이 3개의 강체와 5개의 linear spring으로 이루어진 system으로 모델링 한다.

## 2. Element equilibrium
linear spring을 element로 두고, 강체의 displacement인 $U_1,U_2,U_3$를 state variable로 두자.

각 element의 equilibrium equation은 다음과 같다.
$$\begin{equation} \begin{gathered} k_1U_1 = f_{11} \\ k_2 \begin{bmatrix} 1 & -1 \\ -1 & 1 \end{bmatrix} \begin{bmatrix} U_1 \\ U_2 \end{bmatrix} = \begin{bmatrix} f_{21} \\ f_{22} \end{bmatrix} \\ k_3\begin{bmatrix} 1 & -1 \\ -1 & 1 \end{bmatrix} \begin{bmatrix} U_1 \\ U_2 \end{bmatrix} = \begin{bmatrix} f_{31} \\ f_{32} \end{bmatrix} \\  k_4\begin{bmatrix} 1 & -1 \\ -1 & 1 \end{bmatrix} \begin{bmatrix} U_1 \\ U_3 \end{bmatrix} = \begin{bmatrix} f_{41} \\ f_{43} \end{bmatrix} \\ k_5\begin{bmatrix} 1 & -1 \\ -1 & 1 \end{bmatrix} \begin{bmatrix} U_2 \\ U_3 \end{bmatrix} = \begin{bmatrix} f_{52} \\ f_{53} \end{bmatrix} \end{gathered} \end{equation} $$

## 3. Element assemblage
Element의 interconnection requirements를 서술하기 위해, 전체 system의 force equilibrium equation을 사용하면 다음과 같다.
$$ \begin{equation} \begin{aligned} &f_{11} + f_{21} + f_{31} + f_{41} = R_1 \\ &f_{22} + f_{32} + f_{42} = R_2 \\ &f_{43} + f_{53} = R_3 \end{aligned} \end{equation} $$

식(2)에 식(1)을 적용하기 위해, 식(1)의 식들을 다음과 같이 변형해주자.
$$ \mathbf {K_1d = f_1} \\ \vdots $$

$$ \text{Where, } \mathbf K_1 =  k_1\begin{bmatrix} 1 & 0 &  0 \\ 0 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \enspace \mathbf d = \begin{bmatrix} U_1 \\ U_2 \\ U_3 \end{bmatrix}, \enspace \mathbf f_1 = \begin{bmatrix} f_{11} \\ 0 \\ 0 \end{bmatrix} $$

Force equilibrium equation을 적용하면 다음과 같이 된다.
$$ \mathbf {Kd = f} $$

$$ \text{Where, } \bf K = K_1 + \cdots + K_5, \enspace f = f_1 + \cdots + f_5 = \begin{bmatrix} R_1 \\ R_2 \\ R_3 \end{bmatrix} $$

### 참고1
$\mathbf K_i$를 $i$번째 `element stiffness matrix`라고 하며, $\mathbf K$를 `structure stiffness matrix`라고 한다.

### 참고2
$\mathbf {K_id = f_i}$에서 왼쪽 항은 $i$번째 element에 작용하는 내력을 오른쪽 항은 외력을 나타낸다. 즉, 각 element의 내력과 외력의 평형을 나타내는 식이 된다.

유사하게 $\mathbf {Kd = f}$에서 왼쪽 항은 전체 구조에 작용하는 내력을 오른쪽 항은 외력을 나타낸다. 즉, 전체 구조의 내력과 외력의 평형을 나타내는 식이 된다.