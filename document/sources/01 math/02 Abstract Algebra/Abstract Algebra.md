# Abstract Algebra
이 글은 다음을 정리한 글이다.

[선형대수 - 수학의 즐거움 youtube](https://www.youtube.com/playlist?list=PL4m4z_pFWq2oWmDtNvdy5GYP68dOsGV64)  
[추상대수학 - 수학의 즐거움 youtube](https://www.youtube.com/playlist?list=PL4m4z_pFWq2rDUPj_TPi1IQUgubY3-PtI)





## 분배법칙
집합 $S$와 두 이항연산 $+:S \times S \rightarrow S$, $\cdot : S \times S \rightarrow S$이 있을 때, 다음을 만족할 경우  $\cdot$이 $+$에 대해 `분배법칙(distributive property)`을 만족한다고 한다.

$$ x,y,z \in S, \quad (x+y)\cdot z = x \cdot z + y \cdot z \enspace \land \enspace x \cdot (y+z) = x \cdot y + x \cdot z$$   

## 환
집합 $R$과 두 이항연산 $+:R \times R \rightarrow R$, $\cdot : R \times R \rightarrow R$이 있을 때, `환(ring)` $(R,+,\cdot)$이란 다음을 만족하는 대수 구조이다.

$$ (R,+) \text{ is an Abelian group} \enspace \land \enspace (R,\cdot) \text { is a monoid } \enspace \land \enspace \cdot \text { is distributive w.r.t. } + $$
     
### 명제1

환 $(R,+,\cdot)$이 있을 때, $0_R \equiv e_{(R,+)}, x \in R$에 대해 $0_Rx =0_R$을 증명하여라.

**proof**

$$ 0_Rx  = (0_R + 0_R)x = 0_Rx + 0_Rx \quad \land \quad 0_Rx = 0_Rx + 0_R \\ \therefore 0_Rx = 0_R \quad {_\blacksquare} $$

### 명제2

환 $(R,+,\cdot)$이 있을 때, $x,y \in R$에 대해 $(xy)^{-1}=x^{-1}y$을 증명하여라.

**proof**

$$ (x + x^{-1})y = xy + x^{-1}y = 0_R \\ \therefore (xy)^{-1} = x^{-1}y $$

## 환 준동형 사상 
환 $(R_1,+_1,\times_1),(R_2,+_2,\times_2)$이 있을 때, `환 준동형 사상(ring homomorphism)` $f:R_1 \rightarrow R_2$은 $r_1,r_2 \in R_1$에 대해 다음을 만족하는 함수이다  

$$f(r_1 +_1 r_2)=f(r_1) +_2 f(r_2) \\ f(r_1 \times_1 r_2)=f(r_1) \times_2 f(r_2)$$

## 체
환 $(F,+,\cdot)$이 있을 때, `체(field)`란 다음을 만족하는 환이다.

$$(F-\{e_+\},\cdot) \text{ is a commutative group}  $$

즉, 체는 체는 사칙연산이 자유로이 시행될 수 있고 산술의 잘 알려진 규칙들을 만족하는 대수 구조이다. 

### 예시
$(\R,+,\times), (\mathbb{Q},+,\times)$은 체이다.  

### 참고
모든 체는 가환환이지만 그 역은 성립하지 않는다.

## 가군
아벨 군 $(M,+)$과 환 $(R,+,\cdot)$이 있을 때, 

`왼쪽 가군(left module)` ${_RM}$은 환의 작용 $\cdot: R\times M \rightarrow M$에 대해 다음을 만족하는 아벨 군이다.
1. $r_1,r_2 \in R, \quad m_1,m_2\in M \Rightarrow (r_1 + r_2)(m_1+m_2) = r_1m_1+r_1m_2+r_2m_1+r_2m_2$
2. $r_1,r_2 \in R, \quad m\in M \Rightarrow (r_1r_2)m = r_1(r_2m)$
3. $m \in M \Rightarrow 1_Rm = m$

`오른쪽 가군(right module)` $M_R$은 환의 작용 $\cdot: M \times R \rightarrow M$에 대해 다음을 만족하는 아벨 군이다.
1. $r_1,r_2 \in R, \quad m_1,m_2\in M \Rightarrow (m_1+m_2)(r_1 + r_2) = r_1m_1+r_1m_2+r_2m_1+r_2m_2$
2. $r_1,r_2 \in R, \quad m\in M \Rightarrow m(r_1r_2) = (mr_1)r_2$
3. $m \in M \Rightarrow m1_R = m$

$(R,R)-$`쌍가군(bimodule)` ${_RM_R}$은 두 환의 작용 $\cdot_1: R\times M \rightarrow M$, $\cdot_2: M \times R \rightarrow M$에 대해 각각 왼쪽 가군, 오른쪽 가군이면서 추가적으로 다음을 만족하는 아벨 군이다.

1. $r_1,r_2 \in R, \quad m \in M \Rightarrow (r_1 \cdot_1 m) \cdot_2 r_2 = r_1 \cdot_1 (m \cdot_2 r_2)$

$R$이 가환환일 때, 좌우 구분을 생략하고 그냥 단순히 `R-가군(R-module)`이라고 한다. 

왜냐하면 왼쪽 가군일 때, $r \in R, m \in M$에 대해 $\cdot_2 : M \times R \rightarrow M$를 $r \cdot_1 m = m \cdot_2 r$를 만족하게 정의하면 오른쪽 가군이 된다. 반대로 오른쪽 가군일 때에도 같은 맥락으로 왼쪽 가군이 된다. 즉, 좌우 구분이 의미가 없어지기 때문이다. 

결론적으로 가군은 어떤 환의 작용이 주어진 아벨 군이다. 아벨 군의 구조와 환의 원소에 대한 곱셈이 주어지며, 이 두 구조가 분배 법칙을 통해 서로 호환되는 대수 구조이다. 

### 명제1

R-가군 $(M,+,\cdot)/R$이 있을 때, $x \in M$에 대해 $0_Rx =0_M$을 증명하여라.

**Proof**

$$ \begin{aligned} 0_Rx  & = (0_R + 0_R)x = 0_Rx + 0_Rx \\ 0_Rx & = 0_Rx + 0_M \\ \therefore 0_Rx & = 0_M \end{aligned}   $$

## 가군 준동형 사상
환 $R$과 $R-$가군 $(M_1,+_1,\cdot_1),(M_2,+_2,\cdot_2)$이 있을 때, `가군 준동형 사상(modoule homomorphism)`
$f:M_1 \rightarrow M_2$은 $m_1,m_2 \in M_1, r \in R$에 대해 다음을 만족하는 함수이다.

$$f(m_1 +_1 m_2)=f(m_1) +_2 f(m_2) \\ f(r \cdot_1 m_1)=r \cdot_2 f(m_1)$$

가군 준동형 사상의 경우 $f(rm_1+m_2) = r_1f(m_1)+f(m_2)$를 만족하며 $f$가 `선형성(linearlity)`를 갖고있다고 한다.

이 개념이 선형변환의 일반화이다. 즉, 선형변환읜 대수적 구조를 보존하는 함수의 한 형태이다.

## 벡터공간
Abelian group $(V,+)$와 field $(F,+,\cdot)$가 있을 때, `벡터공간(vector space)` $V/F$란, $F-$module이다.

## 선형 변환
체 $F$와 벡터공간 $V,W/F$이 있을 때, `선형변환(linear transformation)` $\Phi:V \rightarrow W$은 $F-$가군 준동형 사상이다.

