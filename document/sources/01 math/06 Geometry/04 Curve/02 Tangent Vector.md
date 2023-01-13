# Tangent Vector
## 정의
$\R$의 open set $U$와 $r : U \rightarrow\R^n$이 있다고 하자.

$r$로 표현되는 curve를 $C$라 하고 $a \in U$에서 $r$이 differentiable할 때, $a$에서 $C$의 tangent vector $t$는 다음과 같이 정의한다.

$$ t := r'(a) $$

### 참고
Derivative의 정의에 의해 다음이 성립한다.

$$ r'(a) = \lim_{h\rightarrow0}\frac{r(a+h)-r(a)}{h} $$

이 때, $r'(a)$의 기하학적 의미를 살펴보자.

$A_{\R^n}$이 $\R^n$에 affine structure을 준 affine space라고 하자.

$r(a+h),r(h) \in A_{\R^n}$라 보고, $r(a+h)$점을 $Q$, $r(a)$점을 $P$라고 했을 때 다음이 성립한다.

$$ r(a+h) - r(a) = \overline{PQ} $$

```{figure} _image/0201.png
```

$r'(a)$의 정의를 기하학적으로 표현한 위 그림에 잘 나와있듯이, $h$가 작아지면 작아질수록 $\overline{PQ}$는 $P$에 접선과 같은 방향을 갖는 다는걸 알 수 있다.

따라서, $r'(a)$를 $a$에서 $C$의 tangent vector라고 정의한 것이다.

## Unit Tangent Vector
$\R$의 open set $U$와 $r : U \rightarrow\R^n$이 있다고 하자.

$r$로 표현되는 curve를 $C$라 하고 $a \in U$에서 $r$이 differentiable할 때, $a$에서 $C$의 unit tangent vector $t$는 다음과 같이 정의한다.

$$ T:= \frac{r'(a)}{\norm{r'(a)}} $$