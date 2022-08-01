# 1 Introduction
만약 FE discretization이 bending displacement fields of shells를 정확하게 근사하지 못한다면, bending dominated와 mixed shell behaviors에서 부정확한 결과를 얻게 된다. 이런 현상을 locking이라고 하며 shell thickness가 줄어들수록 locking 현상은 심각해진다[2,3,12].

MITC3 element는 useful 하지만 opimal convergence behaviors을 보여주지는 않는다.[1,11]

3-node shell element는 mesh를 generate하기 쉽고, governing global stiffness and mass matrices의 bandwidth가 작다는 장점이 있다. 그러나 이러한 장점에도 불구하고 MITC4 element가 superior performance를 가지고 있기 때문에 일반적으로 MITC4 element가 사용된다. 하지만 이런 사각형 요소는 geometrically distoreted 될 때 convergence behavior가 훼손된다.[22]

일반적으로 3-node triangular elements는 lack of displacement modes때문에 성능이 떨어진다[2,9,10]. 이런 내제적인 한계점을 극복하기 위해 displacment field를 enrich 시키는 방법이 효과적이다[22-25]. 
> Q. 3-node triangular elements는 왜 lack of displacement modes인가?  
> [2] [book] (Bathe) FE procedures 참고  
> [9] [Paper] 2007 (Lee et al) Insight into 3-node triangular shell finite elements the effects of element isotropy and mesh patterns 참고  
> [10] [Paper] 2012 (Lee et al) Improving the MITC3 shell finite element by using the Hellinger–Reissner principle 참고  
> [22] [Paper] 2014 (Jeon et al) The MITC3 shell finite element enriched by interpolation covers 참고  
> [25] [Paper] 2013 (Kim & Bathe) The finite element method enriched by interpolation covers 참고  

3-node triangular element을 위한 cubic bubble function은 요소 내부에서는 higher-order interpolation이 가능하게 하면서 element edge에서는 linear interpolation을 유지하기 때문에 element간의 compatibility를 제공하여 유용하다.
> Q. edge에서 linear interpolation을 유지하면 왜 compatibility between elements를 제공하나?  

MITC3+에서는 bending displacements를 enrich하기 위해 cubic bubble function을 사용해서 rotation을 interpolation한다. 이를 위해 standard 3-node shell element의 dof에 2개의 internal rotation dof가 추가 된다.

그래서 bubble function은 shell element의 mid-surface displacement에 영향을 주지 않는다.

shear locking 현상을 완화하기 위해 new assumed transverse shear strain field가 designed 되었다.

# 2 MITC formulation

## 2.1 MITC3
continuum mechanics displacement-based shell element의 geometry는 다음과 같다.
$$ \mathbf x( r_1,r_2,r_3) = n_i(r_1,r_2) \mathbf x_i + \frac{r_3}{2} n_i(r_1,r_2) a_i \mathbf v^i $$
$$ \text{Where, } n_1 = 1 - r_1 - r_2, \enspace n_2 = r_1, \enspace n_3 = r_2 $$

> Q. geometry가 왜 이렇게 표현되지?  
> (see [book] (Bathe) The finite element shell element chap 6.3)

이 때, $n_i$는 $i$점의 standard 2D shape function이고 $\mathbf x_i$는 $i$점의 직교 좌표이며 $a_i$는 $i$점의 shell thickness, $\mathbf v^i$는 $i$점의 director vector이다. 이 때, $\mathbf v^i$는 shell midsurface에 수직일 필요는 없다.
> Q.director vector가 뭐지?

Element의 displacement는 다음과 같이 주어진다.
$$ \mathbf d(r_1,r_2,r_3) = n_i(r_1,r_2)\mathbf d(\mathbf x_i) + \frac{r_3}{2} a_in_i(-\mathbf v_2^i \alpha_i + \mathbf v_1^i \beta_i) $$
> Q. 왜 displacement가 이렇게 표현되지?  
> (see [book] (Bathe) The finite element shell element chap 6.3)

이 때, $\mathbf v^i_{1,2}$는 각 각 $\mathbf v^i$에 수직한 단위 벡터이고, $\alpha_i, \beta_i$는 rotation of the director vector $\mathbf v^i$ about $\mathbf v^i_{1,2}$.

covariant strain component는 다음과 같다.
$$ e_{ij} = \frac{1}{2} \left( \frac{\partial \bf x}{\partial r_i} \cdot \frac{\partial \bf d}{\partial r_j} + \frac{\partial \bf x}{\partial r_j} \cdot \frac{\partial \bf d}{\partial r_i} \right)$$ 
> Q. covariant strain component가 왜 이렇게 표현되지?  
> (see [book] (Bathe) The finite element shell element chap 4.1)

constant covariant transverse shear strain along the edge를 가정한 MITC3요소의 transverse shear strain은 다음과 같이 주어진다.

$$ \tilde{e}^{MITC3}_{rt} = e_{rt}^{(1)} + cs, \enspace \tilde{e}^{MITC3}_{st} = e_{st}^{(2)} - cr $$
$$ \text{Where, } c = (e^{(3)}_{rt} - e^{(1)}_{rt}) - (e^{(3)}_{st} - e^{(2)}_{st}) $$

## 2.2 MITC3+
`질량중심(barycenter)`에 bubble node를 포함한 continuum mechanics displacement-based MITC3+ element의 geometry는 다음과 같다.
<p align = "center">
<img src = "./image/2014 (Lee et al)_1.png">
</p>

$$ \mathbf x(r_1, r_2, r_3) = \sum_{i = 1}^3 n_i(r_1, r_2) \mathbf x_i + \sum_{i = 1}^4 \frac{r_3}{2} m_i(r_1,r_2) a_i \mathbf v^i $$
$$ \text{Where, } n_1 = 1 - r_1 - r_2, \enspace n_2 = r_1, \enspace n_3 = r_2 \\ m_1 = n_1 - \frac{1}{3}m_4, \enspace m_2 = n_2 - \frac{1}{3}m_4, \enspace m_3 = n_3 - \frac{1}{3}m_4, \enspace m_4 = 27r_1r_2(1-r_1-r_2) \\ a_4 \mathbf v^4 = \frac{1}{3} \sum_{i = 1}^3 a_i \mathbf v^i $$

$m_i$는 2차원 interpolation functions으로 bubble node에 대한 interpolation function인 cubic bubble function $m_4$를 포함하고 있다.

이에 따른, displacement는 다음과 같다.
$$ \mathbf d(r_1,r_2,r_3) = \sum_{i = 1}^3 n_i(r_1,r_2)\mathbf d(\mathbf x_i) + \frac{r_3}{2} \sum_{i = 1}^4 a_i m_i(-\mathbf v_2^i \alpha_i + \mathbf v_1^i \beta_i) $$

이 때, $\alpha_4,\beta_4$는 bubble node를 추가함으로써 추가적으로 생긴 rotation dof이다.

rotation dof만 가지고 있는 bubble node는 중간면의 barycenter에 존재하며, bending과 transverse shear strain fields만 enriched 시키고 element의 gemoetry는 flat하게 유지한다.
> Q. 왜?

MITC3 요소에서는 transverse shear strain components에 mixed interpolation을 적용하였지만 bubble function의 효과를 포함하기 위해서는 새로운 assumed transverse shear strain이 필요하다.

새로운 assumed transverse shear strain을 디자인하기 위해서는 두가지를 고려해야 한다.
* bubble function이 element edge에서 0이 되기 때문에 bubble function을 고려하기 위해서는 tying points가 element edge가 아니라 element 내부에 있어야 한다.
* in-plane twisting mode의 stiffness가 줄어들어야 한다[10].
> Q.왜 in-plane twisting mode의 stiffness를 줄여야 하는가?  
> [Paper] 2012 (Lee et al) Improving the MITC3 shell finite element by using the Hellinger–Reissner principle

bubble node가 포함되지 않은 3-node triangular shell element를 고려해보자. transverse shear strains는 two transverse shearing modes와 in-plane twisting mode에서 일어난다. 이 때, in-plane twisting mode는 barycenter를 축으로 twisting이 발생하여 barycenter에서는 tranverse shear strain이 0인 경우이다.

이를 이용해서 MITC3 shell element의 transverse shear strain을 in-plane twisting mode와 관련없는 constant part와 in-plane twisting mode와 관련된 linear part로 나눌 수 있다.
$$ \tilde{e}^{MITC3}_{rt} = e_{rt}^{const} + e_{rt}^{linear}, \enspace \tilde{e}^{MITC3}_{st} = e_{st}^{const} + e_{st}^{linear} $$

barycenter에서 in-plane twisting mode에 의한 transverse shear strain이 0이기 때문에 constant part는 barycenter에서 transverse shear strain이 된다.
$$ \begin{gathered} e_{rt}^{const} = e_{rt}^{MITC3}|_{s = 1/3} = e^{(1)}_{rt} + \frac{1}{3}c = \frac{2}{3} \Big(e^{(1)}_{rt} + \frac{1}{2}e_{st}^{(2)} \Big) - \frac{1}{3} \Big(e^{(3)}_{st} - e_{rt}^{(3)} \Big) \\ e_{st}^{const} = e_{st}^{MITC3}|_{r = 1/3} = e^{(1)}_{st} - \frac{1}{3}c =  \frac{2}{3} \Big(e^{(2)}_{st} + \frac{1}{2}e_{rt}^{(1)} \Big) + \frac{1}{3} \Big(e^{(3)}_{st} - e_{rt}^{(3)} \Big) \end{gathered} $$

linear part는 다음과 같다.
$$ \begin{gathered} \tilde{e}^{linear}_{rt} = \tilde{e}^{MITC3}_{rt} - e_{rt}^{const} = \frac{1}{3}c(3s-1) \\ \tilde{e}^{linear}_{st} = \tilde{e}^{MITC3}_{st} - e_{st}^{const} = \frac{1}{3}c(1-3r) \end{gathered} $$

만약 this scheme을 new element에 사용한다면, bubble function이 element edge에서 0이기 때문에 constant part는 bubble function의 effect를 포함하지 않게된다. 따라서 constant part에 bubble function의 effect를 포함하기 위해 element internal point를 사용하는 new tying scheme을 디자인한다.

먼저, 아래 그림과 같이 barycenter에서 각각의 corner 방향으로 가는 세게의 covariant transverse shear strain $e_{1t},e_{2t},e_{3t}$를 정의한다.
<p align = "center">
<img src = "./image/2014 (Lee et al)_2.png">
</p>

$e_{1t},e_{2t},e_{3t}$에 대해 다음 관계식들이 성립한다.
$$ \begin{aligned} e_{1t} &= \frac{1}{\sqrt 5}(2e_{st} - e_{rt}) \\ e_{2t} &= \frac{1}{\sqrt 5}(2e_{rt} - e_{st}) \\ e_{3t} &= -\frac{1}{\sqrt 2}(e_{rt} + e_{st}) \end{aligned} $$

이를 $e_{rt},e_{st},e_{qt}$에 대해서 정리하면 다음과 같다.
$$ \begin{aligned} e_{rt} &= \frac{\sqrt 5}{3}e_{2t} - \frac{\sqrt 2}{3}e_{3t} \\ e_{st} &= \frac{\sqrt 5}{3}e_{1t} - \frac{\sqrt 2}{3}e_{3t} \\ e_{qt} &= -\frac{1}{\sqrt 2}(e_{st} - e_{rt}) = \frac{\sqrt 10}{6}(e_{1t} - e_{2t}) \end{aligned} $$

# 알고리즘
MITC3+ 요소에서는 기존의 shell 요소의 barycenter에 bubble node를 추가함으로써, 2개의 rotation dof를 추가하여 mid-surface displacement에는 영향을 주지 않으면서, dispaclement field를 enrich 시킨다.



# 계획
$$\begin{array}{c|l}
월-주차 & 내용 \\ 
\hline 
\\
6-2 & \text{Mecsolver}  \\ 
6-3 & \text{ - Shell의 Element stiffness matrix 계산 코드 이해}     \\ 
6-4 & \sout{\text{ \;- Shell의 Elasticity Tensor 계산 코드 이해}}   \\
    & \text{ \;- Shell의 B matrix 계산 코드 이해}                   \\ 
    & \sout{\text{ \;\;- Shell의 B membrane matrix 계산 코드 이해}} \\ 
    & \sout{\text{ \;\;- Shell의 B bending matrix 계산 코드 이해}}  \\ 
    & \sout{\text{ \;\;- Shell의 B shear matrix 계산 코드 이해}}    \\     
    & \sout{\text{ \;\;- Simo \& Fox 논문 이해}}                    \\     
\\
\hline
\\ 
7-1 & \sout{\text{2004 MITC isotropic triangular 논문 정리 및 이해}} \\ 
7-2 & \\ 
7-3 & \\ 
\\
\hline 
\\
7-4 & \text{2014 MITC3+ 논문 스터디} \\ 
8-1 & \text{ - 정리 문서 만들기} \\ 
8-2 & \text{ - 알고리즘 정리 문서 만들기} \\ \\
    & \text{MITC3+ 요소와 Mecsolver 요소 성능 비교하기} \\
    & \text{ - 논문 자료만으로 성능 비교가 어려워 보류} \\
    
\\ 
\hline 
\\
8-3 & \text{MITC3+ 구현 및 검증} \\
8-4 & \\ 
9-1 & \\ 
9-2 & \\ \\ \hline \\
9-3 & \text{2017 new 4-node MITC 논문 정리 및 이해} \\
9-4 & \\ \\ \hline \\
10-1 & \text{2017 new MITC4+ 논문 정리 및 수식화} \\ 
10-2 & \\  \\ \hline \\
10-3 & \text{MITC4+ 구현} \\
10-4 & \\ 

\end {array}$$

Shell theory 
7월 3째주에 중간발표
학위논문 찾아보기