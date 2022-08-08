# Strong formulation

`경계값 문제(boudnary value problem)`가 다음과 같이 주어졌다고 하자.  
$$ \begin{equation} \text{find } u \in \mathcal U \quad s.t. \quad \mathcal P(u) + f(\mathbf x) = 0 \quad \text{in } \Omega \subset \R^d \end{equation} $$

$$ \text{Where, } \mathcal U := \{ u \in C^m(\Omega) \enspace | \enspace u \text{ satisfies boundary condition on } \partial\Omega \} $$

이 때, $\mathcal P : C^m(\Omega) \rightarrow C^0(\Omega)$는 `계수(order)`가 $m$인 `미분 연산자(differential operator)`이며 $\mathcal U$는 `solution funtion space`이다.

`경계조건(boundary condition; BC)`은 $\partial\Omega_E \subset \partial\Omega$따라 essential BC와 $\partial\Omega_N \subset \partial\Omega$따라 natural BC가 주어져있으며 $\partial\Omega = \partial\Omega_E \cup \partial\Omega_N$ 이다.

식(1)을 PDE의 `strong formulation`이라 하는데 이는 strong formulation의 해가 $\Omega$의 모든 점에서 PDE를 만족시켜야하며 $m$번 미분 가능해야된다는 엄격한 `정규성(regularity)`을 만족시켜야하기 때문이다.

# Collocation method
무한차원 함수공간인 $\mathcal U$에서 식(1)을 만족하는 $u$를 찾는 것은 매우 어려운 일임으로,  축소된 $n$차원 공간 $\mathcal U_h : = \text{span}(\{\mu_1, \cdots, \mu_n \})$을 생각해보자. 

이 때, $\mathcal U_h$에 대해 다음이 성립한다.
$$u \in \mathcal U_h \Rightarrow u = a_i \mu_i$$





> 참고  
> [wiki](https://en.wikipedia.org/wiki/Spaces_of_test_functions_and_distributions)
> [wiki2](https://www.google.com/search?q=collocation+method+&ei=_zDuYoCrBZLg2roPkJeIqAQ&ved=0ahUKEwjApoGZ8LH5AhUSsFYBHZALAkUQ4dUDCA4&uact=5&oq=collocation+method+&gs_lcp=Cgdnd3Mtd2l6EAMyBQgAEIAEMgUIABCABDIFCAAQgAQyBAgAEB4yBAgAEB4yBAgAEB4yBAgAEB4yBAgAEB4yBAgAEB4yBAgAEB46DgguEIAEELEDEMcBENEDOggIABCABBCxAzoLCAAQgAQQsQMQgwE6EQguEIAEELEDEIMBEMcBENEDOgcILhCABBAKOgUILhCABDoGCAAQHhAKSgQIQRgASgQIRhgAUABYuQ1ghytoAHABeAGAAXaIAa0PkgEEMy4xNpgBAKABAcABAQ&sclient=gws-wiz)