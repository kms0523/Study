# Kernel
## 정의
Vector space $V,W / \mathbb F$와 $T \in L(V,W)$가 있을 때, 다음과 같이 정의된 집합을 $T$의 `kernel`이라고 한다.

$$ \ker(T) := \{ v \in V \enspace | \enspace T(v) = 0_W \} $$

### 명제1
vector space $V,W/\F$가 있다고 하자.

$L(V;W)$의 임의의 element를 $f$라고 할 때, 다음을 증명하여라.

$$ 0_V \in \ker(f)$$

**Proof**

$V$의 임의의 element를 $v$라고 하면 다음이 성립한다.

$$ f(v) = f(v+0_V) = f(v) + f(0_V) \implies f(0_V) = 0_W \qed $$

### 명제2
유한 차원 vector space $V,W / \mathbb F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.

$$ \ker(T) \text{ is a subspace of } V $$

**Proof**

[Abelian Group]  
-[closed]  
$\ker(T)$의 임의의 element를 $v_1,v_2$라고 하자.

$T$가 linear map임으로 다음이 성립한다.

$$ T(v_1+v_2) = T(v_1) + T(v_2) = 0_W $$

따라서 $v_1 + v_2 \in \ker(T)$이고 그럼으로 $\ker(T)$는 $+$에 닫혀있다. $\qed$

-[identity]  
$T(0_V) = 0_W$임으로 $0_V \in \ker(T)$이고 $\ker(T)$의 모든 element는 $V$의 element임으로 다음이 성립한다.

$$ 0_V \text{ is an identity of } \ker(T) \qed $$

-[inverse]  
$\ker(T)$의 임의의 element를 $v$라고 하자.

$v \in V$임으로 inverse element는 $-v \in V$이고 다음이 성립한다.

$$ T(-v) = - T(v) = 0_W $$

따라서 $-v \in \ker(T)$임으로 $\ker(T)$는 inverse element를 갖는다. $\qed$

-[commutative]   
$\ker(T)$의 임의의 element를 $v_1,v_2$라고 하자.

$v_1,v_2 \in V$임으로 다음이 성립한다.

$$ v_1 + v_2 = v_2 + v_1 \qed $$

[$\F-$Module]  
$\ker(T)$의 임의의 element를 $v$라고 하자.

$\F$의 임의의 element를 $c$라고 할 때, 다음이 성립한다.

$$ T(cv) = cT(v) = c0_W = 0_W \implies cv \in \ker(T) $$

따라서, $\ker(T)$는 $V$의 scalar multiplication에 닫혀있음으로, scalar multiplication을 그대로 사용하면 자명하게 $\ker(T)$는 $\F-$module이다.

[결론]
따라서 $\ker(T)$는 vector space이고 다음이 성립한다.

$$ \ker(T) \text{ is a subspace of } V \qed  $$

### 명제3
유한 차원 vector space $V,W / \mathbb F$과 $T \in L(V,W)$가 있을 때, 다음을 증명하여라.

$$ \ker(T) = \{ 0_V \} \iff T \text{ is injective} $$

**Proof**

[$\implies$]  
$V$의 임의의 element를 $v_1,v_2$라고 하면 다음이 성립한다.

$$ \begin{aligned} & T(v_1) = T(v_2) \\ \implies \enspace & T(v_1) - T(v_2) = T(v_2) - T(v_2) \\ \implies \enspace & T(v_1 - v_2) = 0_W \\ \implies \enspace & v_1 - v_2 = 0_V \\ \implies \enspace & v_1 = v_2 \qed \end{aligned} $$

[$\impliedby$]  
$T(0_V) = 0_W$이고 $T$가 injective임으로 $\ker(T) = \{ 0_V \}$이다. $\qed$

## Nullity
Vector space $V,W / \mathbb F$와 $T \in L(V,W)$가 있다고 하자.

이 때, $V$의 subspace $\ker(T)$의 dimension을 $\nullity(T)$ 라고 한다.

$$ \nullity(T) := \dim(\ker(T)) $$