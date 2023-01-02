# Fundamental Lemma of Variation Caculus
$\Omega \subset \R^d$와 $f \in C^0(\Omega)$가 있다고 할 때 다음을 증명하여라.  
$$ f = 0 \text{ on } \Omega \iff \forall w \in C^\infty_c(\Omega), \int_\Omega w f \thinspace dV = 0 $$

**Proof**

[$\implies$]  
$f = 0$이면 $\forall w \in C^\infty_c(\Omega), \int_\Omega w f \thinspace dV = 0$는 자명하게 참이다. $\qed$

[$\impliedby$]  
다음을 가정하자.

$$ f \neq 0 \text{ on } \Omega $$

따라서, 다음이 성립한다.

$$ \exist\Omega_h \subseteq \Omega \st f(\Omega_h)>0 \lor f(\Omega_h)<0 $$

-[$f(\Omega_h) > 0$]  
Bump function의 existence가 보장되기 때문에 다음이 성립한다.

$$ \exist w \in C^\infty_c(\Omega) \quad s.t. \quad w \in C^\infty_c(\Omega_h) \enspace \land \enspace w(\Omega_h) >0 $$

따라서 다음이 성립한다.

$$ \int_\Omega w f \thinspace dV = \int_{\Omega_h} w f \thinspace dV > 0 $$

이는 전제에 모순된다.

-[$f < 0$ on $\Omega_h$]  
위와 비슷한 방법으로 전제에 모순이 발생함을 알 수 있다.

-[결론]  
따라서, proof by contradiction에 의해 다음이 성립한다.

$$ f = 0 \text{ on } \Omega \qed $$

> Reference  
> [note - Ananthasuresh](https://mecheng.iisc.ac.in/suresh/me256/notes3_2007.pdf)  
> [math.stackexchange](https://math.stackexchange.com/questions/1792102/alternative-proof-of-fundamental-lemma-of-variational-calculus)  

denseness of smooth function proof

> Reference  
> [last answer - Mathematics](https://math.stackexchange.com/questions/1805184/the-dirac-delta-does-not-belong-in-l2)