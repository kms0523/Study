$\Omega \subset \R^d$와 $f \in C^0(\Omega)$가 있다고 할 때 다음을 증명하여라.  
$$ f = 0 \text{ on } \Omega \Leftrightarrow \forall w \in \mathcal W , \int_\Omega w f \thinspace dV = 0 $$

$$ \text{Where, } C^\infty_c(\Omega) \subset \mathcal W $$

**Proof**

[$\Rightarrow$]  
$f = 0$이면 $\forall w \in \mathcal W , \int_\Omega w f \thinspace dV = 0$는 자명하게 참이다. $\quad {_\blacksquare}$

[$\Leftarrow$]  
$\forall w \in \mathcal W , \int_\Omega w f \thinspace dV = 0$일 때, $f \neq 0 \text{ on } \Omega$이라 가정하자.

$f \neq 0$이기 때문에 $f > 0$이거나 $f < 0$인 부분이 반드시 존재해야한다. 이 부분을 $\Omega_h \subseteq \Omega$라 하자.

[$f > 0$ on $\Omega_h$]  
bump function의 existence가 보장되기 때문에 다음이 성립한다.
$$ \exist w_h \in \mathcal W \quad s.t. \quad w_h \in C^\infty_c(\Omega_h) \enspace \land \enspace w_h >0 $$

따라서 다음이 성립한다.
$$ \int_\Omega w_h f \thinspace dV = \int_{\Omega_h} w_h f \thinspace dV > 0 $$

이는 가정에 모순된다.

[$f < 0$ on $\Omega_h$]  
위와 동일한 방법으로 모순이 발생함을 보일 수 있다.

결론적으로, 위 가정에 의해 모순이 발생함으로  $\forall w \in \mathcal W , \int_\Omega w f \thinspace dV = 0$일 때, $f = 0 \text{ on } \Omega$이다. $\quad {_\blacksquare}$


> 참고  
> [note] (Ananthasuresh) Fundamental lemmas of calculus of variations  
> [alternative-proof-of-fundamental-lemma-of-variational-calculus - Mathematics](https://math.stackexchange.com/questions/1792102/alternative-proof-of-fundamental-lemma-of-variational-calculus)  

denseness of smooth function proof

> 참고  
> [last answer - Mathematics](https://math.stackexchange.com/questions/1805184/the-dirac-delta-does-not-belong-in-l2)