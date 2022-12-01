# Vector Space Isomorphism
벡터 공간 $V,W/F$과 $\Phi \in L(V;W)$가 있다고 하자.

$\Phi^{-1}:W \rightarrow V \in L(W;V)$면 $\Phi$를 `벡터 공간 동형 사상(vector space isomorphism)`이라고 한다.

### 명제1  
유한 차원 벡터 공간 $V,W/F$와 $\Phi \in L(V,W)$가 있을 때 다음을 증명하여라.  

$$\Phi \text{ is bijective} \Rightarrow \Phi^{-1} \in L(W,V)$$

**Proof**  

$\Phi$가 전단사 함수임으로 $\exist! \Phi^{-1}$이고 $v_1,v_2 \in V$에 대해 $\exist!w_1,w_2 \in W, \Phi(v_1)=w_1, \Phi(v_2)=w_2$이다.

$$\begin{aligned} & \Phi(av_1 + v_2) = aw_1 + w_2 \\ \Leftrightarrow \enspace & av_1 + v_2 = \Phi^{-1}(aw_1 + w_2) \\ \Leftrightarrow \enspace & \Phi^{-1}(aw_1 + w_2) = a\Phi^{-1}(w_1) + \Phi^{-1}(w_2) \quad {_\blacksquare}  \end{aligned} $$

### 명제2
유한 차원 벡터 공간 $V,W/F$, $V$의 기저 $\beta = \{ v_1, \cdots, v_n \}$ 그리고 벡터 공간 동형 사상 $\Phi:V \rightarrow W$이 있을 때, 다음을 증명하여라.

$$ R :=  \{ \Phi(v_1),\cdots,\Phi(v_n) \} \text { is a basis of } W$$

**Proof**  

[ proof of $R$ is linearly independent ]  
$$\begin{aligned} & a_1\Phi(v_1)+\cdots+a_n\Phi(v_n) = 0_W \\ \Leftrightarrow \enspace & \Phi(a_1v_1+\cdots+a_nv_n) = \Phi(0_V) \\ \Rightarrow \enspace & a_1v_1 + \cdots + a_nv_n = 0_V \\ \Rightarrow \enspace & a_1= \cdots = a_n = 0_F \quad {_\blacksquare} \end{aligned} $$

[ proof of $span(R)=W$  ]  
-[ $span(R) \subseteq W$ ]  
$R \subseteq W$ 임으로 생성의 명제1에 의해 증명된다. $\quad {_\blacksquare}$

-[ $W \subseteq span(R)$ ]  
$$ \begin{aligned} & w \in W, \quad \exists! v \in V \quad s.t \quad \Phi(v) = w \\ \Rightarrow \enspace & w = \Phi(a_1v_1 + \cdots + a_nv_n) = a_1\Phi(v_1)+\cdots+a_n\Phi(v_n) \\ \Rightarrow \enspace & w \in span(R) \quad {_\blacksquare} \end{aligned} $$


# Vectorspace Isomorphic
유한 차원 벡터 공간 $V,W/ \mathbb F$와 벡터 공간 동형 사상 $\Phi:V \rightarrow W$가 있을 때, $V$와 $W$를 `벡터 공간 동형(vector space isomorphic)`이라고 하고 $V \overset{\Phi \;}{\cong} W$ 또는 $V \cong W$라고 표기한다.

### 명제1
유한 차원 벡터 공간 $V,W/F$가 있을 때, 다음을 증명하여라.

$$V \cong W \iff \dim(V)=\dim(W)$$

**Proof**  

[$\Rightarrow$]  
$V$의 기저 $\beta$와 vector space isomorphism $\Phi:V \rightarrow W$가 있을 때, 벡터 공간 동형 사상의 명제2에 $\Phi(\beta)$은 $W/F$의 기저가 된다.

따라서 $\dim(V)=\dim(W)$. $\quad {_\blacksquare}$

[$\Leftarrow$]  
$\beta, \gamma$를 $V,WF$의 기저라고 할 때, 함수 $\varphi$를 다음과 같이 정의하자.
$$\varphi:V \rightarrow W \quad s.t \quad \beta_i \mapsto \gamma_i$$  

이 때, $\varphi$가 벡터 공간 동형 사상임을 보이자.

[$\varphi \in L(V,W)$]  
$v_1 = a^i\beta_i, v_2 = b^i\beta_i \in V, c \in F$에 대해,

$$ \begin{aligned} \varphi(cv_1+v_2) &= (ca^i + b^i)\gamma_i \\ &= ca^i\gamma_i + b^i\gamma_i \\ &= c\varphi(v_1) + \varphi(v_2) \quad {_\blacksquare} \end{aligned} $$

[$\varphi$ is bijective]  
$\ker(\varphi) = \{ 0_V \}$이고 $\dim(V) = \dim(W)$임으로 dimension theorem에 의해 $\varphi$는 bijective이다.$\quad {_\blacksquare}$

### Remark
차원을 통해 Vector space를 분류할 수 있다. 즉, 차원이 같으면 벡터 공간 동형이고 차원이 다르면 벡터 공간 동형이 아닌 경우로 분류가 된다.

벡터 공간 동형은 집합론적 관점에서 동치 관계를 만족한다. 따라서 분할을 갖게 되며 차원이 같은 경우에는 동일한 그룹으로 볼 수 있다는것을 의미한다.

이 때, $F^n = F\times \cdots \times F$은 $\dim(F^n)=n$임으로 임의의 $n$ 차원 벡터 공간 $V$와 $V \cong F^n$이다. 이를통해 매우 추상적인 벡터 공간 $V$와 실질적인 $F^n$을 동일한 그룹으로 볼 수 있다. 그리고 이 관계를 통해 추상적인 $V$를 편하게 서술할 수 있는 관점을 제공 받는다.