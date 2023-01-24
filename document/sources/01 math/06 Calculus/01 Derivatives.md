# Derivatives
## 정의
open set $U \subset \R$과 함수 $f : U \rightarrow \R$이 있다고 하자.

$a \in U$에서 $f$의 `미분(derivatives)`은 다음과 같이 정의된다.

$$ f'(a) := \lim_{h \rightarrow 0} \frac{1}{h}(f(a + h) - f(a)) $$

> Reference  
> {cite}`hubbard` chap 1.7

### 참고1
극한값이 존재하는 경우 `미분가능(differentiable)`하다고 한다.

### 참고2
$f'$은 $U$의 변화량과 그에 따른 $f$의 변화량의 비율의 극한이다.

$$ \frac{\text{change in }f}{\text{change in }U} = \frac{f(a+h)-f(a)}{h}  $$

### 참고3(Alternative Form)
위의 정의를 다차원으로 확장하기 위해 open set $U \subset \R^n$와 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$a \in U$에서 $f'$은 $U$의 변화량과 그에 따른 $f$의 변화량의 비율의 극한임으로 다음과 같다.

$$ f'(a) := \lim_{h \rightarrow 0_{\R^n}} \frac{1}{h}(f(a + h) - f(a)) $$

이 떄, $h \in \R^n$임으로 vector로 나눈다는것은 정의되지 않은 연산이다.

따라서, 다차원으로의 확장을 고려하면 기존의 정의를 다른 형태로 변형해야 한다.

#### Altenative form1
다차원 확장을 고려하여 정의를 다음과 같이 변경해보자.

$$ f'(a) := \lim_{h \rightarrow 0} \frac{1}{|h|}(f(a + h) - f(a)) $$

이 경우에는 다차원으로 확장하더라도 vector의 크기로 나누기 때문에 정의되지 않은 연산은 없다. 

하지만 이 경우에는 $h \rightarrow 0$로 가면서 부호 문제가 발생하여 기존의 미분 가능하던 함수들이 미분 불가능하게 된다.

##### 예시
$f(x) = x^2$라 하자.

$f'(a)$를 계산하면 다음과 같다.

$$ f'(a) = \lim_{h \rightarrow 0} \frac{1}{|h|}(2ah + h^2) = \begin{cases} 2a & h>0 \\ -2a & h<0 \end{cases} $$

따라서, 극한값이 존재하지 않아 미분불가능해지는 문제가 발생한다.

#### Alternative form2
기존의 미분 정의로부터 다음 형태를 유도할 수 있다.

$$ \lim_{h \rightarrow 0} \frac{1}{h} \Big( f(a + h) - f(a) - f'(a)h \Big) = 0 $$

따라서, 위의 형태와 다차원으로 확장을 고려하여 다음과 같이 정의를 변경해보자.

$$ \lim_{h \rightarrow 0} \frac{1}{|h|} \Big( f(a+h)-f(a)-L(h) \Big) = 0 $$

이 때, 위의 식을 만족하는 함수 $L(h)$를 $hf'(a)$라고 정의하면 Alternative form1과 다르게 부호 문제가 발생하지 않는다.

##### 참고1
$f(a + h) - f(a)$항은 $\Delta f$를 나타내고, $L(a)h$항은 $\Delta f$를 선형근사한 값으로 볼 수 있다.

##### 참고2
위의 식이 성립하기 위해서는 $\Delta f$와 선형근사인 $L(a)h$사이의 차이가 $h \rightarrow 0$일 때, 선형보다 작아야 한다.

###### 예시
linear map $L,D$가 있다고 하자.

$L$은 $\Delta f - L(h) = c_1h, \enspace c_1 \in \R - \{ 0 \}$로 차이가 선형이라고 하면 다음과 같다.

$$ \lim_{h \rightarrow 0} \frac{1}{|h|} \Big( f(a+h)-f(a)-L(h) \Big) = \lim_{h \rightarrow 0}\frac{c_1h}{|h|} = \pm c_1 \neq 0 $$

즉, 차이가 선형인 경우 위의 식을 만족시키지 못한다.

$D$는 $\Delta f - D(h) = c_2h^2, \enspace c_2 \in \R - \{ 0 \}$로 차이가 선형보다 작다고 하면 다음과 같다.

$$ \lim_{h \rightarrow 0} \frac{1}{|h|} \Big( f(a+h)-f(a)-D(h) \Big) = \lim_{h \rightarrow 0}\frac{c_2 h^2}{|h|} = 0 $$

즉, 차이가 선형보다 작은 경우 위의 식을 만족시킨다.

### 명제1(Chain Rule)
$\R$의 open set $U,V$와 함수 $f : U \rightarrow V, g : V \rightarrow \R$이 있다고 하자.

$f$가 $a \in U$에서 differentiable하고 $g$가 $f(a) \in V$에서 differentiable할 때, 다음을 증명하여라.

$$ \begin{gathered} g \circ f \text{ is diffrentiable at } a \\ (g \circ f)'(a) =g'(f(a))f'(a) \end{gathered} $$

**Proof**

함수 $r,s : \R \rightarrow \R$를 다음과 같이 정의하자.

$$ \begin{gathered} r(h) = f(a+h) - f(a) - f'(a)h \\ s(h) = g(f(a)+h) - g(f(a)) - g'(f(a))h \end{gathered} $$

$r$의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} (g\circ f)(a+h) &= g(f(a+h)) \\&= g(f(a) + r(h) + f'(a)h) \\&= g(f(a) + \Delta f) \end{aligned} $$

$s$의 정의에 의해 다음이 성립한다.

$$ \begin{aligned} g(f(a) + \Delta f) = g(f(a)) + g'(f(a))\Delta f + s(\Delta f)  \end{aligned} $$

이를 정리하면 다음이 성립한다.

$$ \frac{(g\circ f)(a+h) - (g\circ f)(a)}{h}  = g'(f(a))\frac{\Delta f}{h} + \frac{s(\Delta f)}{h} $$

이 때, 보조명제1.1,1.2에 의해 다음이 성립한다.

$$ \lim_{h\rightarrow0}\frac{\Delta f}{h} = f'(a), \enspace \lim_{h\rightarrow0}\frac{s(\Delta f)}{h} = 0 $$

따라서, 다음이 성립한다.

$$ \lim_{h\rightarrow0}\frac{(g\circ f)(a+h) - (g\circ f)(a)}{h}  = g'(f(a))f'(a) $$

미분의 정의에 의한 극한값이 존재함으로 다음이 성립한다.

$$ \begin{gathered} g \circ f \text{ is diffrentiable at } a \\ (g \circ f)'(a) =g'(f(a))f'(a) \end{gathered} \qed $$


#### 보조명제1.1
다음을 증명하여라.

$$ \lim_{h\rightarrow0}\frac{\Delta f}{h} = f'(a) $$

**Proof**

$\Delta f$를 풀어 쓰면 다음과 같다.

$$ \Delta f = f(a+h) - f(a) $$

$f$가 $a$에서 미분 가능함으로 다음이 성립한다.

$$ \lim_{h\rightarrow0}\frac{\Delta f}{h} = f'(a) \qed $$

#### 보조명제1.2
다음을 증명하여라.

$$ \lim_{h\rightarrow0}\frac{s(\Delta f)}{h} = 0 $$

**Proof**

다음과 같이 수식을 변경하자.

$$ \begin{aligned} \frac{s(\Delta f)}{h} &= \frac{s(\Delta f)}{\Delta f}\frac{\Delta f}{h} \end{aligned}  $$

$s$의 정의에 의해 다음이 성립한다.

$$ \frac{s(\Delta f)}{\Delta f} = \frac{g(f(a)+\Delta f) - g(f(a))}{\Delta f}  - g'(f(a)) $$

이 때, $\Delta f$의 정의에 의해 다음이 성립한다.

$$ \lim_{h\rightarrow0} \Delta f = \lim_{h\rightarrow0} (f(a+h) - f(a)) = 0$$

따라서 다음이 성립한다.

$$ \begin{aligned} \lim_{h\rightarrow0}\frac{s(\Delta f)}{\Delta f} &= \lim_{h\rightarrow0}\left(\frac{g(f(a)+\Delta f) - g(f(a))}{\Delta f}  - g'(f(a))\right) \\&= \lim_{\Delta f \rightarrow0} \frac{g(f(a)+\Delta f) - g(f(a))}{\Delta f} - g'(f(a)) \\&= 0 \end{aligned} $$

그럼으로, 다음이 성립한다.

$$ \lim_{h\rightarrow0}\frac{s(\Delta f)}{h} = 0f'(a) = 0 \qed $$

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
{cite}`stewart` chapter 2.5  
[blog-Paul's online note](https://tutorial.math.lamar.edu/Classes/CalcI/DerivativeProofs.aspx)  






