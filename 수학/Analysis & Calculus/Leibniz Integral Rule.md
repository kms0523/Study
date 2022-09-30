# 1D

> Referebce  
> [Wiki - Leibniz integral rule ](https://en.wikipedia.org/wiki/Leibniz_integral_rule)  

# 3D Generalization
$$ \frac{d}{dt} \int_{\Omega(t)} f(x,t) \thinspace dV = \int_{\Omega(t)} \frac{\partial}{\partial t} f \thinspace dV + \frac{d}{dt} \int_{\partial\Omega(t)} f(v_b(x,t) \cdot n(x,t)) \thinspace dS$$

$n$은 $\partial\Omega(t)$의 outward unit normal vector이며 $v_b$는 $x$에서의 $\partial \Omega(t)$의 velocity vector이다.

이 때, $\Omega(t)$를 material element라고 하고 물질의 속도를 $v$라고 한다면 다음이 성립한다.
$$ \frac{d}{dt} \int_{\Omega(t)} f \thinspace dV = \int_{\Omega(t)} \frac{\partial}{\partial t} f \thinspace dV + \frac{d}{dt} \int_{\partial\Omega(t)} f(v \cdot n) \thinspace dS$$

**Proof**

물질 좌표를 $X$라 할 때, deformation이 다음과 같이 정의되어 있다고 하자.
$$ x = \varphi(X,t) $$

따라서 deformation gradient $F$는 다음과 같다.
$$ F(X,t) = \nabla \varphi $$

$f$를 $X$로 나타내면 다음과 같다.
$$ \hat f(X,t) = f( \varphi(X,t),t) $$

$\Omega_0$가 $\Omega(t)$의 reference configuration이라고 하면 다음이 성립한다.
$$ \begin{aligned} \int_{\Omega} f(x,t) \thinspace dV &= \int_{\Omega_0} f(\varphi(X,t),t) \det(F) \thinspace dV_0 \\&= \int_{\Omega_0} \hat f(X,t) \det(F) \thinspace dV_0 \\&= \int_{\Omega_0} \hat f(X,t) J \thinspace dV_0 \end{aligned} $$

따라서, 다음이 성립한다.
$$ \begin{aligned} \frac{d}{dt} \left( \int_{\Omega} f(x,t) \thinspace dV \right) &= \lim_{\Delta t \rightarrow 0} \frac{1}{\Delta t} \left( \int_{\Omega(t + \Delta t)} f(x,t + \Delta t) \thinspace dV  - \int_{\Omega(t)} f(x,t) \thinspace dV \right) \\&= \lim_{\Delta t \rightarrow 0} \frac{1}{\Delta t} \left( \int_{\Omega_0} \hat f(X,t + \Delta t) J(X, t + \Delta t) - \hat f(X,t) J(X,t) \thinspace dV_0 \right) \\&= \int_{\Omega_0} \left( \lim_{\Delta t \rightarrow 0} \frac{ \hat f(X,t + \Delta t) J(X, t + \Delta t) - \hat f(X,t) J(X,t) \thinspace dV_0}{\Delta t} \right) \thinspace dV_0 \\&= \int_{\Omega_0} \left( \frac{\partial}{\partial t} \hat f(X,t) J(X, t) \right) \thinspace dV_0 \\&= \int_{\Omega_0} \left( \frac{\partial}{\partial t}( \hat f(X,t)) J(X, t) + \hat f(X,t)\frac{\partial}{\partial t}(J(X, t)) \right) \thinspace dV_0 \end{aligned} $$

> Reference  
> [Wiki - Reynolds transport theorem](https://en.wikipedia.org/wiki/Reynolds_transport_theorem)  

### 명제1
다음을 증명하여라.
$$ \frac{\partial}{\partial t} \det(F) = \det(F)\text{div}(v) $$


> Reference  
> [Book] (Lai et al) Introduction to Continuum Mechanics chap 7.4  
> [Wiki - Jacobi's formula](https://en.wikipedia.org/wiki/Jacobi%27s_formula)  


#### 보조명제
다음을 증명하여라.
$$ \text{tr}(F^{-1} \frac{\partial}{\partial t} F) = \text{div}(v) $$

> Reference  
> [Book] (Gurtin) An Introduction to Continuum Mechanics p.63