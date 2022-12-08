# 들어가며

이 글은 아래 글들을 정리한 내용이다.

[Newton's method - Wiki](https://en.wikipedia.org/wiki/Newton%27s_method#Description)  
[Gauss–Newton algorithm - Wiki](https://en.wikipedia.org/wiki/Gauss%E2%80%93Newton_algorithm)  


# 뉴턴 방법
뉴턴 방법(Newton's method) 혹은 뉴턴-랩슨 방법(Newton-Raphons method)이라고 불리는 방법은 실함수(real-valued function) $f$의 근을 찾는 방법이며 이는 $f=0$ 방정식의 해를 찾는것과 동일하다.

## 일변수함수
미분가능한 일변수 함수 $f:\R \rightarrow \R$가 주어졌을때 근 $x$를 찾고자 한다.
$$ \text{find} \quad x \in \R \quad s.t. \quad  f(x)=0 $$

알고리즘은 다음 순서로 이루어진다.
1. $k=0$으로 두고 초기 해 $x_0$를 예측한다
2. $x_k$에서 $f$를 선형근사한다.
$$ y= f'(x_k)(x - x_k) + f(x_k) $$
3. 선형근사한 함수의 해를 $x_{k+1}$로 둔다.
$$ x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)} $$
4. $x_{k+1}$이 convergence criterion을 만족하는지 확인한다.
$$ |f(x_{k+1})| \le \epsilon \enspace \land \enspace N \le k+1    $$
5. Convergence criterion을 만족하면 다음과 같이 해를 결정한다.
$$ x = x_{k+1} \enspace \land \enspace \text{ Exit algorithm } $$
6. Convergence criterion을 만족하지 않는다면 $k = k + 1$로 두고 step2로 돌아간다.


## 벡터함수
미분가능한 벡터 함수 $f:\R^n \rightarrow \R^m$가 주어졌을 때 근 $x$를 찾고자 한다.
$$ \text{find} \quad x \in \R^n \quad s.t. \quad  f(x)=0_n $$

이는 다음 연립방정식의 해를 찾는 것과 동일하다.
$$ \begin{cases}
\begin{matrix}
f_1(x) = 0  \\
\vdots \\
f_m(x) = 0    
\end{matrix}
\end{cases} $$

$$ f = \begin{bmatrix}
   f_1 \\ \vdots \\ f_m
\end{bmatrix}, \quad f_i : \R^n \rightarrow \R, \quad i=1,\cdots,m $$

### $n=m$
1. $k=0$으로 두고 초기 해 $x_0$를 예측한다
2. $x_k$에서 $f$를 선형근사한다.
$$ y= J_f(x_k)(x - x_k) + f(x_k) $$
3. 선형근사한 함수의 해를 $x_{k+1}$로 둔다.
$$ x_{k+1} = x_k - J_f(x_k)^{-1} f(x_k) $$
4. $x_{k+1}$이 convergence criterion을 만족하는지 확인한다.
$$ |f(x_{k+1})| \le \epsilon \enspace \land \enspace N \le k+1    $$
5. Convergence criterion을 만족하면 다음과 같이 해를 결정한다.
$$ x = x_{k+1} \enspace \land \enspace \text{ Exit algorithm } $$
6. Convergence criterion을 만족하지 않는다면 $k = k + 1$로 두고 step2로 돌아간다.

### $n<m$
알고리즘은 다음 순서로 이루어진다.
1. 초기 해 $x_0$를 예측한다
2. $x_0$에서 $f$를 선형근사한다.
$$ y= J_f(x_0)(x-x_0)+f(x_0) $$
3. 선형근사한 함수의 해를 찾는다.   
   만약 선형근사한 함수의 해가 없는 경우, least square sense의 해를 찾게 되며 Gauss-Newton 알고리즘과 동일해진다.
$$ x_1 = x_0 - J^{\dagger}_f(x_0)f(x_0)$$
$$ \text{where,} \quad J_f^{\dagger} \equiv ((J_f)^TJ_f)^{-1}(J_f)^T $$
4. $x_1$는 $x_0$ 보다 해에 대해 더 나은 근사이다. 이 과정을 원하는 수준의 근사까지 반복한다.
$$ x_{n+1} = x_n - J_f(x_n)^{-1}f(x_n) $$

# 응용
최대값과 최소값에서는 $f'=0$이기 때문에 뉴턴 방법을 $f'$에 적용하여 최대값과 최소값을 찾을 수 있다.

## 일변수 함수
2계 미분가능한 일변수 함수 $f:\R \rightarrow \R$가 주어졌을때 $f$가 최소 혹은 최대값을 갖는 $x$를 찾고자 한다.
$$ \text{find} \quad x \in \R \quad s.t. \quad  f'(x)=0 $$

알고리즘은 다음 순서로 이루어진다.
1. 초기 해 $x_0$를 예측한다
2. $x_0$에서 $f'$를 선형근사한다.
$$ y= f''(x_0)(x-x_0)+f'(x_0) $$
3. 선형근사한 함수의 해를 찾는다.
$$ x_1 = x_0 - \frac{f'(x_0)}{f''(x_0)} $$
4. $x_1$는 $x_0$ 보다 해에 대해 더 나은 근사이다. 이 과정을 원하는 수준의 근사까지 반복한다.
$$ x_{n+1} = x_n - \frac{f'(x_n)}{f''(x_n)} $$

## 다변수 함수
2계 미분가능한 다변수 함수 $f:\R^n \rightarrow \R$가 주어졌을때 $f$가 최소 혹은 최대값을 갖는 $x$를 찾고자 한다.
$$ \text{find} \quad x \in \R^n \quad s.t. \quad  \nabla f(x)=0 $$

알고리즘은 다음 순서로 이루어진다.
1. 초기 해 $x_0$를 예측한다
2. $x_0$에서 $\nabla f$를 선형근사한다.
$$ y= H_f(x_0)(x-x_0)+\nabla f(x_0) $$
3. 선형근사한 함수의 해를 찾는다.
$$ x_1 = x_0 - (H_f)^{-1}(x_0)\nabla f(x_0) \\
\text{where,} \quad H_f \equiv \frac{\partial ^2 f}{\partial x_i \partial x_j} $$
4. $x_1$는 $x_0$ 보다 해에 대해 더 나은 근사이다. 이 과정을 원하는 수준의 근사까지 반복한다.
$$ x_{n+1} = x_n - (H_f)^{-1}(x_n)\nabla f(x_n) $$

# 가우스-뉴턴 알고리즘
가우스-뉴턴(Gauss–Newton) 알고리즘은 벡터함수의 least square 문제를 푸는 알고리즘이다. 이 알고리즘은 뉴턴 방법을 이용해서 함수의 최소값을 찾는 방식의 한 응용이다. 함수의 최대 최소값을 찾는 뉴턴 방법과는 다르게 가우스-뉴턴 알고리즘은 함수값의 제곱의 합이 최소가 되는 값을 찾는 방식이다. 가우스 뉴턴 알고리즘은 계산이 어려운 2계 미분을 구하지 않아도 되는것이 뉴턴 방법 대비 장점이다.

## 알고리즘
2계 미분가능한 다변수 함수 $f:\R^n \rightarrow \R^m$가 주어졌을때 $s$가 최소가 되는 $x$를 찾고자 한다.
$$ \text{find} \quad x \in \R^n \quad s.t. \quad \argmin s(x) $$
$$ \text{where,} \quad s(x) = \sum _{i=1} ^ m f_i^2(x) $$

여기서 $s(x)$는 다변수 함수임으로, 다변수 함수에서 뉴턴 방법을 적용해보자.
$$ \nabla s =2 \sum _{i=1}^{m} f_i \frac{\partial f_i}{\partial x_j} =2 (J_f)^T f $$
$$ \Rightarrow H_s =2 \sum _{i=1}^{m} \left(  \frac{\partial f_i}{\partial x_j} \frac {\partial f_i}{ \partial x_k} + f_i \frac{\partial ^2 f_i}{\partial x_j \partial x_k}  \right)   $$

만약 $H_s$에서 2계 미분항을 무시하게 되면 $H_s$를 다음과 같이 간략하게 나타낼 수 있다.

$$ H_s \approx 2 \sum _{i=1}^{m} \frac{\partial f_i}{\partial x_j} \frac {\partial f_i}{ \partial x_k} = 2(J_f)^TJ_f  $$

따라서
$$ x_1 = x_0 - (H_s)^{-1}(x_0)\nabla s(x_0) $$
$$ \Rightarrow x_1 = x_0 - J^{\dagger}_f(x_0)f(x_0) $$
$$ \Rightarrow x_{n+1} = x_n - J^{\dagger}_f(x_n)f(x_n) $$
$$ \text{where,} \quad  J_f^{\dagger} \equiv ((J_f)^TJ_f)^{-1}(J_f)^T $$



$$ x_1 = x_0 - (H_s)^{-1}(x_0)\nabla s(x_0) \\
\Rightarrow x_1 = x_0 - J^{\dagger}_f(x_0)f(x_0) \\
\Rightarrow x_{n+1} = x_n - J^{\dagger}_f(x_n)f(x_n) \\
\text{where,} \quad  J_f^{\dagger} \equiv ((J_f)^TJ_f)^{-1}(J_f)^T $$
