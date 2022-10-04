# 1D

> Referebce  
> [Wiki - Leibniz integral rule ](https://en.wikipedia.org/wiki/Leibniz_integral_rule)  

# 3D Generalization
3차원에서 일반화된 Leibniz integral rule은 다음과 같다.
$$ \frac{d}{dt} \int_{\Omega(t)} f(x,t) \thinspace dV = \int_{\Omega(t)} \frac{\partial}{\partial t} f \thinspace dV + \int_{\partial\Omega(t)} f(v_b(x,t) \cdot n(x,t)) \thinspace dS$$

이 때, $n$은 $\partial\Omega(t)$의 outward unit normal vector이며 $v_b$는 $x$에서의 $\partial \Omega(t)$의 velocity vector이다.

## Derivation
물질 좌표를 $X$라 할 때, deformation이 다음과 같이 정의되어 있다고 하자.
$$ x = \varphi(X,t) $$

따라서 deformation gradient $F$는 다음과 같다.
$$ F(X,t) = \nabla \varphi $$

그러면 $f_m$은 다음과 같다.
$$ f_m(X,t) = f(\varphi(X,t),t) $$

$\Omega_0$가 $\Omega(t)$의 reference configuration이라고 하면 다음이 성립한다.
$$ \begin{aligned} \int_{\Omega} f(x,t) \thinspace dV &= \int_{\Omega_0} f(\varphi(X,t),t) \det(F) \thinspace dV_0 \\&= \int_{\Omega_0} f_m \det(F) \thinspace dV_0 \\&= \int_{\Omega_0} f_m J \thinspace dV_0 \end{aligned} $$

따라서, 다음이 성립한다.
$$ \begin{aligned} \frac{d}{dt} \left( \int_{\Omega} f(x,t) \thinspace dV \right) &= \lim_{\Delta t \rightarrow 0} \frac{1}{\Delta t} \left( \int_{\Omega(t + \Delta t)} f(x,t + \Delta t) \thinspace dV  - \int_{\Omega(t)} f(x,t) \thinspace dV \right) \\&= \lim_{\Delta t \rightarrow 0} \frac{1}{\Delta t} \left( \int_{\Omega_0} f_m(X,t + \Delta t) J(X, t + \Delta t) - f_m J \thinspace dV_0 \right) \\&= \int_{\Omega_0} \left( \lim_{\Delta t \rightarrow 0} \frac{ f_m(X,t + \Delta t) J(X, t + \Delta t) - f_m J \thinspace dV_0}{\Delta t} \right) \thinspace dV_0 \\&= \int_{\Omega_0} \left( \frac{\partial}{\partial t} f_m J \right) \thinspace dV_0 \\&= \int_{\Omega_0} \left( J\frac{\partial}{\partial t} f_m + f_m\frac{\partial}{\partial t}J \right) \thinspace dV_0 \end{aligned} $$

> Reference  
> [Wiki - Reynolds transport theorem](https://en.wikipedia.org/wiki/Reynolds_transport_theorem)  

### 명제1
$F$를 deformation gradient라고 하자.

이 때, 다음을 증명하여라.
$$ \frac{\partial}{\partial t} \det(F) = \det(F)\text{div}(v) $$

**Proof**




> Reference  
> [Book] (Lai et al) Introduction to Continuum Mechanics chap 7.4  
> [Wiki - Jacobi's formula](https://en.wikipedia.org/wiki/Jacobi%27s_formula)  


#### 보조명제
다음을 증명하여라.
$$ \text{tr}(F^{-1} \frac{\partial}{\partial t} F) = \text{div}(v) $$

> Reference  
> [Book] (Gurtin) An Introduction to Continuum Mechanics p.63

## Material volume & Control volume
$\Omega_0$를 reference figure라고 하고 Material volume $\Omega_m(t)$와 control volume $\Omega_c$를 다음과 같이 정의하자.
$$ \Omega_m(t) := \{ x(X,t) \enspace | \enspace X \in \Omega_0 \} \\ \Omega_c := \Omega_m(t_0) $$

$\Omega = \Omega_m$이라 하면 $t = t_0$에서 Leibniz integral rule은 다음과 같이 표현할 수 있다.
$$ \begin{aligned} & \frac{d}{dt} \int_{\Omega_m} f \thinspace dV \bigg|_{t= t_0} = \int_{\Omega_c} \frac{\partial}{\partial t} f \bigg|_{t= t_0} \thinspace dV + \int_{\partial\Omega_c} f(v_s \cdot n) \thinspace dS \end{aligned} $$

이 때, $v_s(x,t) = v_m(X,t)$는 $\Omega_m$에 속한 물질의 속도이다.

> [Book] (Lai et al) Introduction to Continuum Mechanics chap 7.4  
