# Normal Subgroup

## Definition
Group $G$와 subgroup $H$가 있다고 하자.

이 떄, 다음을 만족하는 $H$를 $G$의 `normal subgroup`이라고 한다.

$$ \forall g \in G, \forall h \in H, \enspace ghg^{-1} \in H $$

### Remark
1. $H$가 normal subgroup일 경우, $H \lhd G$라고 표기한다.
2. $G$가 commutative group일 경우, $G$의 모든 subgroup은 normal subgroup이다.
3. $\Set{e}$와 $G$는 항상 normal subgroup이다.
4. Group $G$와 normal subgroup $N$이 있다고 하자. 그러면 $N$의 성질에 의해 $G/N$은 quotient group이 된다. $G/N$은 일반적으로 $G$보다 단순한 구조를 가지고 있으며, 이를 통해 $G$의 복잡한 구조를 이해하는 한가지 좋은 방법을 제공한다.

> Reference  
> [math.stackexchange](https://math.stackexchange.com/questions/2626414/importance-of-normal-subgroups)

### 명제1
Group $G$와 subgorup $H$가 있다고 하자.

이 떄, 다음을 증명하여라.

$$ H \lhd G \iff \forall g \in G, \enspace gH = Hg $$

**Proof**

[$\implies$]  
-[$gH \subseteq Hg$]  
$gH$의 임의의 element를 $gh$라고 하면 전제에 의해 다음이 성립한다.

$$ \exist h_2 \in H \st ghg^{-1} = h_2 \implies gh = h_2g \implies gh \in Hg \qed $$

-[$Hg \subseteq gH$]  
$Hg$의 임의의 element를 $hg$라고 하면 전제에 의해 다음이 성립한다.

$$ \exist h_2 \in H \st g^{-1}hg = h_2 \implies hg = gh_2 \implies hg \in gH \qed $$

[$\impliedby$]  
$G$의 임의의 element를 $g$, $H$의 임의의 element를 $h$라고 하면 전제에 의해 다음이 성립한다.

$$ \exist h_2 \in H \st gh = h_2g \implies ghg^{-1} = h_2 \implies ghg^{-1} \in H \qed $$

### 명제2
Group $G,G'$과 group homomorphism $\phi:G\rightarrow G'$이 있다고 하자.

이 때, 다음을 증명하여라.

$$ \ker(\phi) \lhd G $$

**Proof**

$G$의 임의의 element를 $g$, $\ker(\phi)$의 임의의 element를 $h$라고 하면 다음이 성립한다.

$$ \phi(ghg^{-1}) = \phi(g)\phi(h)\phi(g^{-1}) = e_G \implies ghg^{-1} \in \ker(\phi) \qed $$

#### Remark
$\img(\phi) \lhd G'$이라고 해보자.

이 때, $\phi = id$로 두면 $G'$의 모든 subgroup이 normal subgroup이 된다.

하지만 반례가 있음으로 proof by contradiction에 의해 $\img(\phi)$는 $G'$의 normal subgroup이 아니다.

##### CounterExample1
$M := \Set{m \in M_{22}(\R) | \det(m) \neq 0}$라고 할 때, $(M,\times)$은 group이다.

이 때, $M$의 subgroup $H$을 다음과 같이 정의하자.

$$ H= \Braket{\begin{bmatrix} 1&1\\0&1 \end{bmatrix}} = \Set{\begin{bmatrix} 1&k\\0&1 \end{bmatrix} \mid k \in \Z} $$

그러면 $ m = \begin{bmatrix} 2&1\\1&1 \end{bmatrix} \in M$과 $ h =\begin{bmatrix} 1&1\\0&1 \end{bmatrix} \in H$에 대해 다음이 성립한다.

$$ mhm^{-1} = \begin{bmatrix} -1&1\\-1&3 \end{bmatrix} \notin H $$

따라서, $H$는 normal subgroup이 아닌 subgroup이다.

##### CounterExample2
$G = D_3:=\Set{r,s \mid r^3=s^2=e, \enspace rs = sr^{-1}}, H= \Set{1,s}$라고 하자.

이 떄, $G$의 element를 $r$, $H$의 element를 $s$라고 하면, $rsr^{-1} = r^2s \notin H$이다.

따라서, $H$는 normal subgroup이 아닌 subgroup이다.

### 명제3
Group $G,G'$과 group epimomorphism $\phi:G\rightarrow G'$이 있다고 하자.

그리고 set $\mathcal{A,B}$와 function $\varphi$를 다음과 같이 정의하자.

$$ \begin{gathered} \mathcal{A} := \Set{H \subseteq G \mid \ker(\phi) \subseteq H \lhd G}, \enspace \mathcal{B} := \Set{ H' \subseteq G' \mid H' \lhd G'} \\ \varphi : \mathcal{A} \rightarrow \mathcal{B} \st H \mapsto \phi(H) \end{gathered} $$

이 떄, 다음을 증명하여라.

$$ \varphi \text{ is a bijective } $$

**Proof**

[$\phi(H) \in \mathcal{B}$]   
$\mathcal{A}$의 임의의 element를 $H$라고 하고 $G'$의 임의의 element를 $g'$, $\phi(H)$의 임의의 element를 $\phi(h)$라고 하자.

$\phi$가 epimorphism임으로 다음이 성립한다.

$$ \exist g \in G \st g' = \phi(g) $$

그리고 $H\lhd G$임으로 다음이 성립한다.

$$ g'h(g')^{-1} = \phi(g)\phi(h)\phi(g)^{-1} = \phi(ghg^{-1}) \in \phi(H) $$

그럼으로 $\phi(H) \lhd G'$이고 $\phi(H) \in \mathcal{B}$이다. $\qed$

[well-defined]  
$\mathcal{A}$의 임의의 element를 $H_1,H_2$라고 하자.

그러면 다음이 성립한다.

$$ H_1 = H_2 \implies \phi(H_1) = \phi(H_2) \implies \varphi(H_1) = \varphi(H_2) \qed $$

[injective]  
$\mathcal{A}$의 임의의 element를 $H_1,H_2$라고 하면 다음이 성립한다.

$$ \varphi(H_1) = \varphi(H_2) \implies \phi(H_1) = \phi(H_2) \implies \preimg(\phi(H_1)) = \preimg(\phi(H_2)) $$

이 때, $\ker(\phi) \subseteq H_1,H_2$임으로 다음이 성립한다.

$$ \preimg(\phi(H_1)) = \preimg(\phi(H_2)) \implies H_1 = H_2 $$

[surjective]  
$\mathcal{B}$의 임의의 element를 $H'$라고 하자. 

$\preimg(H') = H$라고 하면 $e_{G'} \in H'$임으로 $\ker(\phi) \subseteq H$이다.

$G$의 임의의 element를 $g$, $H$의 임의의 element를 $h$라고 하면 $\phi(h) \in H'$이고 $H' \lhd G'$임으로 다음이 성립한다.

$$ \phi(g)\phi(h)\phi(g)^{-1} = \phi(ghg^{-1}) \in H' \implies ghg^{-1} \in H \implies H \lhd G $$

따라서, $\exist H \in \mathcal{A} \st \phi(H) = H'$이다. $\qed$

### 명제4
Group $G$와 subset $H$, normal subgroup $N$이 있다고 하자.

이 때, 다음을 증명하여라.

$$ N \le H \le G \implies N \lhd H $$

**Proof**

전제에 의해 $N$은 $H$의 subgroup이다.

그리고 $N$의 임의의 element를 $n$ $H$의 임의의 element를 $h$라고 하면 $h \in G$이고 $N \lhd G$임으로 다음이 성립한다.

$$ hnh^{-1} \in N \qed $$

### 명제5
Group $G$와 subset $H$, normal subgroup $N$이 있다고 하자.

$HN := \Set{hn \mid h \in H, \enspace n \in N}$이라고 할 때, 다음을 증명하여라.

$$ HN \le G $$

**Proof**

$HN=NH$이면 $HN \le G$임으로 $HN=NH$임을 보이자.

[$HN \subseteq NH$]  
$HN$의 임의의 element를 $hn$이라고 하자. 

$N \lhd G$임으로 다음이 성립한다.

$$ \exist n_2 \in N \st  hnh^{-1} = n_2 $$

따라서, 다음이 성립한다.

$$ hn = hnh^{-1}h = n_2h \in NH \qed $$

[$NH \subseteq HN$]  
$NH$의 임의의 element를 $nh$라고 하자. 

$N \lhd G$임으로 다음이 성립한다.

$$ \exist n_2 \in N \st  h^{-1}nh = n_2 $$

따라서, 다음이 성립한다.

$$ nh = hh^{-1}nh = hn_2 \in HN \qed $$






