# Directional Derivative
## Motivation
$\R^n$의 open set을 $U$라고 하고 다변수 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$a \in U$에서 일변수 함수의 미분계수의 정의를 그대로 다변수 함수의 미분계수로 확장해보자.

$$ \lim_{h\rightarrow 0}\frac{f(a+h) - f(a)}{h} $$

위의 식을 살펴보면 $a$는 vector이고 $h$는 scalar인데 정의되지 않는 $+$연산을 하고 있다.

또한 일변수 함수의 경우 $a$에 가까워 지는것이 한가지 방향으로만 가능하기 때문에 $h\rightarrow 0$으로 그 의미가 충분히 표현된다.

하지만 다변수 함수의 경우 $a$에 가까워 지는 방향이 무한가지이기때문에 $h\rightarrow 0$만으로 그 의미가 충분히 표현되지 못한다.

따라서, 특정 방향 $v \in \R^n \st \norm{v} = 1$을 정해서 

//그림//

따라서, 다변수 함수로 일차원 미분계수의

## 정의
open subset $U \subset \R^n$과 함수 $f:U \rightarrow \R^m$이 있다고 하자.

$f$의 `directional derivative`는 다음과 같이 정의된 함수이다.

$$ Df : U \times \R^n \rightarrow \R^m \st (a,v) \mapsto \lim_{h \rightarrow 0}\frac{ f(a + h v) - f (a)}{h} $$

### 참고1(notation)
$Df(a,v)$는 $D_vf(a)$와 같이 표기하는 것이 일반적이다.

### 참고2
$D_vf(a)$는 $a$에서 $v$방향으로 변화량과 그에 따른 $f$의 변화량의 비율의 극한을 의미한다.

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

### 명제
open set $U \subset \R^n$과 함수 $f : U \rightarrow \R^m$이 있다고 하자.

$\R^m$의 basis를 $\beta$하고 $\forall a \in U$에서 $f$가 differentiable일 때, 다음을 증명하여라.

$$ Df\text{ is well-defined} \enspace\land\enspace \mathfrak{m_\beta}(D_vf(a)) = \mathfrak{m_\beta}(J_f(a)v) $$

**Proof**

$f$가 differentiable 함으로 다음이 성립한다.

$$ \begin{aligned} & \lim_{h \rightarrow 0}\frac{f(a + hv) -f (a) - L_a(hv)}{\norm{hv}} = 0 \\\implies& \lim_{h \rightarrow 0}\frac{f(a + hv) -f (a) - hL_a(v)}{h\norm{v}} = 0 \\\implies& \lim_{h \rightarrow 0}\frac{f(a + hv) -f (a) - hL_a(v)}{h} = 0 \\\implies& \lim_{h \rightarrow 0}\frac{f(a + hv) -f (a)}{h} = L_a(v) \end{aligned} $$

이 떄, $f$가 $a$에서 differentiable 함으로, 선형변환 $L_a$은 잘 정의된다. 

따라서, 극한값이 $L_a(v)$로 존재함으로, 함수 $Df$는 잘 정의된다.

또한, $D_vf(a) = L_a(v)$이고 Jacobian matrix의 정의에 따라 $L_a(v) = J_f(a)v$



> Reference  
> {cite}`hubbard` Proposition 1.7.14.

