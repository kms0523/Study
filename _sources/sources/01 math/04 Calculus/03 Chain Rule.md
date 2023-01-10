# Chain Rule
### 명제1
미분 가능한 두 함수 $f(x),g(x)$가 있을 때, 다음을 증명하여라.
$$ \frac{d(f \circ g)(x)}{dx} = (f' \circ g)(x)g'(x)  $$

$$ \frac{d(f \circ g)}{dx} = \frac{df}{dg}\frac{dg}{dx} $$

**Proof**

Taylor series expansion에 의해 다음이 성립한다.
$$ \begin{aligned} g(x+h) &= g(x) + hg'(x) + O(h^2) \\&= g(x) + h(g'(x) + O(h)) \\&= g(x) + \Delta g \\ f(g(x+h)) &= f(g(x) + \Delta g) \\&= f(g(x)) + \Delta gf'(g(x)) + O(\Delta g^2) \end{aligned}  $$

따라서, 미분의 정의에 의해 다음이 성립한다.
$$ \begin{aligned} \frac{d}{dx} f(g(x)) &= \lim_{h \rightarrow 0} \frac{f(g(x+h)) - f(g(x))}{h} \\&= \lim_{h \rightarrow 0} \frac{\Delta gf'(g(x)) + O(\Delta g^2)}{h} \\&= \lim_{h \rightarrow 0} f'(g(x))(g'(x)+O(h)) + h(g'(x) + O(h))^2 \\&= f'(g(x))g'(x) \qed \end{aligned} $$

### 명제2
미분 가능한 두 함수 $f,g$가 있다고 하자.

이 때, 다음을 증명하여라.
$$ \lim_{h \rightarrow 0} \frac{f(g(x+h))-f(g(x))}{h} =  \lim_{h \rightarrow 0} \frac{f(g(x) + hg'(x))-f(g(x))}{h}$$

**Proof**

$hg'(x) = \Delta g$라 두면 다음이 성립한다.
$$ \begin{aligned} f(g(x) + hg'(x)) &= f(g(x) + \Delta g) \\&= f(g(x)) + \Delta gf'(g(x)) + O(\Delta g^2) \end{aligned} $$

따라서, 다음이 성립한다.
$$ \begin{aligned} \lim_{h \rightarrow 0} \frac{f(g(x) + hg'(x)) - f(g(x))}{h} &= \lim_{h \rightarrow 0} \frac{\Delta gf'(g(x)) + O(\Delta g^2)}{h} \\&= \lim_{h \rightarrow 0} f'(g(x))(g'(x)) + h(g'(x))^2 \\&= f'(g(x))g'(x) \end{aligned} $$

명제1에 의해 다음이 성립한다.
$$ \lim_{h \rightarrow 0} \frac{f(g(x+h))-f(g(x))}{h} = f'(g(x))g'(x) $$

그럼으로 다음이 성립한다.
$$ \lim_{h \rightarrow 0} \frac{f(g(x+h))-f(g(x))}{h} =  \lim_{h \rightarrow 0} \frac{f(g(x) + hg'(x))-f(g(x))}{h} \qed $$


>참고  
[Book] (J. Stewart) Calculus chapter 2.5  
[blog-Paul's online note](https://tutorial.math.lamar.edu/Classes/CalcI/DerivativeProofs.aspx)  
