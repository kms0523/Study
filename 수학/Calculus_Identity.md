## 1

$$ A_{ij} = A_{ji} \land \frac{\partial f}{\partial x_i} = A_{ij}x_j \Rightarrow f = \frac{1}{2} A_{ij} x_j x_i$$

**Proof**

$$ \begin{aligned} & \frac{\partial f}{\partial x_1} = A_{11}x_1 + \cdots + A_{1n}x_n \\ \Rightarrow \quad & f = \frac{1}{2} A_{11}(x_1)^2 + (A_{12}x_2 + \cdots + A_{1n}x_n)x_1 + g_2 (x_2, \cdots, x_n) \\ \Rightarrow \quad & \frac{\partial f}{\partial x_2} = A_{12}x_1 + \frac{\partial g_2}{\partial x_2} = A_{21}x_1 + \cdots + A_{2n}x_n \\ \Rightarrow \quad & \frac{\partial g_2}{\partial x_2} = A_{22}x_2 + \cdots + A_{2n}x_n \quad (\because A_{ij} = A_{ji}) \\ \Rightarrow \quad & g_2 = \frac{1}{2} A_{22}(x_2)^2 + (A_{22}x_3 + \cdots + A_{2n}x_n)x_2 + g_3(x_3, \cdots, x_n) \end{aligned}  $$

$$ \vdots $$

$$ f = \frac{1}{2} \left( A_{11}(x_1)^2 + \cdots + A_{nn}(x_n)^2 \right) + (A_{12}x_2 + \cdots A_{1n}x_n)x_1 + \cdots + A_{n-1n}x_n \\ \therefore f= \frac{1}{2} A_{ij}x_jx_i \quad \left( \because A_{ij}x_jx_i = \frac{1}{2}(A_{ij} + A_{ji})x_jx_i \right) $$


## 2

$$ C_{ijkl} = C_{klij} \land C_{ijkl}\epsilon_{kl} = \frac{\partial f}{\partial \epsilon_{ij}} \Rightarrow f = \frac{1}{2} C_{ijkl}\epsilon_{kl} \epsilon_{ij} $$

**Proof**

1번의 증명과 동일한 과정으로 증명된다.
