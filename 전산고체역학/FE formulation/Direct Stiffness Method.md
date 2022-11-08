# Problem
<p align = "center">
<img src = "./image/spring1.png">
</p>

위 그림과 같이 3개의 강체와 5개의 linear spring으로 이루어진 system이 equilibrium 상태에 있다고 하자.

강체에 가해진 힘 $R_{1,2,3}$가 주어졌을 때, 강체의 displacement $U_{1,2,3}$을 구해보자.

# Element Equilibrium Equation
먼저, linear spring을 element, 강체를 node라고 하자.

$f_{ij}$가 $i$ element가 $j$ node에 가하는 힘이라고 할 떄, 각 element의 force equilibrium equation은 다음과 같다.
$$ \begin{aligned} k_1U_1 &= f_{11} \\ k_2 \begin{bmatrix} 1 & -1 \\ -1 & 1 \end{bmatrix} \begin{bmatrix} U_1 \\ U_2 \end{bmatrix} &= \begin{bmatrix} f_{21} \\ f_{22} \end{bmatrix} \\ k_3\begin{bmatrix} 1 & -1 \\ -1 & 1 \end{bmatrix} \begin{bmatrix} U_1 \\ U_2 \end{bmatrix} &= \begin{bmatrix} f_{31} \\ f_{32} \end{bmatrix} \\  k_4\begin{bmatrix} 1 & -1 \\ -1 & 1 \end{bmatrix} \begin{bmatrix} U_1 \\ U_3 \end{bmatrix} &= \begin{bmatrix} f_{41} \\ f_{43} \end{bmatrix} \\ k_5\begin{bmatrix} 1 & -1 \\ -1 & 1 \end{bmatrix} \begin{bmatrix} U_2 \\ U_3 \end{bmatrix} &= \begin{bmatrix} f_{52} \\ f_{53} \end{bmatrix} \end{aligned} $$

# Node Equilibirum Equation
각 node의 force equilibrium equation은 다음과 같다.
$$ \begin{aligned} &f_{11} + f_{21} + f_{31} + f_{41} = R_1 \\ &f_{22} + f_{32} + f_{42} = R_2 \\ &f_{43} + f_{53} = R_3 \end{aligned} $$

# Direct Stiffness Method
Element의 force equilibrium equation을 다음과 같이 표현하자.
$$ K_id = f_i \enspace (i = 1,\cdots,5) $$

$$ \begin{aligned} \text{Where, } K_1 &=  k_1\begin{bmatrix} 1 & 0 &  0 \\ 0 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \enspace K_2 = k_2\begin{bmatrix} 1 & -1 &  0 \\ -1 & 1 & 0 \\ 0 & 0 & 0 \end{bmatrix} \\  K_3 &=  k_3\begin{bmatrix} 1 & -1 &  0 \\ -1 & 1 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \enspace K_4 = k_4\begin{bmatrix} 1 & 0 &  -1 \\ 0 & 0 & 0 \\ -1 & 0 & 1 \end{bmatrix} \\ K_5 &= k_5\begin{bmatrix} 0 & 0 & 0 \\ 0 & 1 & -1 \\ 0 & -1 & 1 \end{bmatrix} \\ f_1 &= \begin{bmatrix} f_{11} \\ 0 \\ 0 \end{bmatrix}, \enspace f_2 = \begin{bmatrix} f_{21} \\ f_{22} \\ 0 \end{bmatrix} , \enspace f_3 = \begin{bmatrix} f_{31} \\ f_{32} \\ 0 \end{bmatrix}, \enspace f_4 = \begin{bmatrix} f_{41} \\ 0 \\ f_{43} \end{bmatrix}, \enspace f_5 = \begin{bmatrix} 0 \\ f_{52} \\ f_{53} \end{bmatrix} \\ d &= \begin{bmatrix} U_1 \\ U_2 \\ U_3 \end{bmatrix}  \end{aligned} $$

위 식들을 다 더하고(direct summation) node의 force equillibrium equation을 적용하면 다음과 같다.
$$ Kd = f $$

$$ \text{Where, } K = K_1 + \cdots + K_5, \enspace f = f_1 + \cdots + f_5 = \begin{bmatrix} R_1 \\ R_2 \\ R_3 \end{bmatrix} $$



> Reference  
> [Book] (Bathe) Finite Element Procedures p.79  
> [Book] (Fung et al) Classical and Computational Solid Mechanics chap 18