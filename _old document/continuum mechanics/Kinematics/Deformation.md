# Figure
어떤 기준이 되는 시점에 연속체를 이루고 있는 점의 집합을 `reference figure` $\Omega_0$라 한다.

이후 연속체가 운동하는 과정에서 연속체에 변형이 발생하였다고 하자.

이 떄, 변형된 연속체를 이루고 있는 점의 집합을 `deformed figure` $\Omega$라 한다.

# Deformation
Reference figure를 $\Omega_0$, deformed figure를 $\Omega$라 하자.

Material point $X \in \Omega_0$가 시간 $t$가 지난 후 point $x \in \Omega$가 되며 이 관계가 벡터함수 $\varphi$로 나타난다고 하자.
$$ \varphi : \Omega_0 \times \R \rightarrow \Omega \quad s.t \quad (X,t) \mapsto x  $$

그러면 $\varphi$에 의해서 연속체 내부에 있는 모든 점의 변형된 위치가 서술되며 $\varphi$를 `변형(deformation)`이라고 한다.

### 참고
$\varphi$는 특정 점의 특정 시간에서 변형된 위치를 서술함으로 물리적으로 말이 되기 위해서는 주어진 $(X,t)$마다 유일한 $x$가 존재해야 하며, 동시에 모든 $x$에 대해서 $(X,t)$가 존재해야 한다. 

즉, 물리적으로 말이 되기 위해서 $\varphi$는 반드시 전단사 함수여야 하며 역함수가 존재해야한다.

# Displacement 
연속체 한 점의 `변위(displacement)` $\bf d$는 다음과 같이 정의한다.
$$  d(X, t) = \varphi(X, t) - X $$

