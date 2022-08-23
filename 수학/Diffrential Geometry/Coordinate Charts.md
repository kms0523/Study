# Coordinate Charts
$n$차원 topological manifold $M$이 있을 때, $M$의 open subset $U$와 $\R^n$의 open subset $\hat U$이 있다고 하자.

$\varphi : U \rightarrow \hat U$가 homeomorphism일 때, $M$ 위의 `coordinate chart` 혹은 `chart`는 $(U, \varphi)$이다.

$p \in M$를 domain으로 갖는 어떤 chart $(U, \varphi)$에서 $\varphi(p) = 0_{\R^n}$이라면, 이러한 chart를 `centered at` $p$라고 한다. 만약, $(U, \varphi_2)$가 domain으로 $p$를 갖지만, $\varphi_2(p) \neq 0$이라면, $\varphi_3 = \varphi_2 - \varphi_2(p)$를 이용해 centered at $p$ chart $(U,\varphi_3)$를 쉽게 얻을 수 있다.

> Reference  
> [Book] (John M Lee) Introduction to smooth manifolds chap.1