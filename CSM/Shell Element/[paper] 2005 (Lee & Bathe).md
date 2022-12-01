# The basic shell mathematical model
## Shell geometry
Shell의 midsurface를 $S$, $\R^2$의 bounded ope subset을 $w$라 하자.

injective mapping인 2D chart $\phi$에 의해 $w$가 $S$로 mapping된다.
$$ \phi : w \rightarrow S $$

$S$의 basis는 다음과 같다.
$$ a_\alpha = \frac{\partial \phi (\xi^1, \xi^2)}{\partial \xi^\alpha}, \enspace \alpha = 1,2 $$

$S$의 단위 접선 벡터는 다음과 같다.
$$ a_3 = \frac{a_1 \times a_2}{\Vert a_1 \times a_2 \Vert} $$

shell의 3D geometry는 다음과 같은 3D chart $\Phi$로 표현된다.
$$ \Phi(\xi^1,\xi^2,\xi^3) = \phi(\xi^1,\xi^2) + \xi^3a_3(\xi^1,\xi^2) $$

3D reference domain은 다음과 같다.
$$ \Omega := \Big\{ (\xi^1, \xi^2, \xi^3) \in \R^3 \enspace | \enspace ( \xi^1, \xi^2) \in w, \enspace \xi^3 \in \Big[ -\frac{t}{2}, \frac{t}{2} \Big] \Big\} $$

이 때, $t$는 shell의 두깨이다.

$S$의 surface tensors를 정의해보자.

$S$의 first fundamental form인 2D metric tensor는 다음과 같다.
$$ a_{\alpha\beta} = a_\alpha \cdot a_\beta, \enspace a^{\alpha\beta} = a^\alpha \cdot a^\beta, \enspace \alpha,\beta = 1,2$$

$S$의 second fundamental form인 curvature tesnosr는 다음과 같다.
$$ b_{\alpha\beta} = a_3 \cdot \frac{\partial a_\alpha}{\partial \xi^\beta} $$

mixed components인 경우에는 다음과 같다.
$$ b^\alpha_\beta = a^{\alpha \lambda} b_{\lambda \beta} $$

$S$의 third fundamental form은 다음과 같다.
$$ c_{\alpha\beta} = b^\lambda_\alpha b_{\lambda \beta} $$

covariant differentiation of a generic surface vector with component $w_\alpha$는 다음과 같다.
$$ w_{\alpha | \beta} = w_{\alpha, \beta} - \Gamma^\lambda_{\alpha \beta} w_\lambda $$

이 때, $\Gamma^\lambda_{\alpha \beta}$는 Christoffel symbol로 다음과 같이 정의 된다.
$$ \Gamma^\lambda_{\alpha \beta} = \frac{\partial a_\alpha}{\partial \xi ^\beta} \cdot a ^\lambda $$

3D basis vector는 다음과 같다.
$$ g_i = \frac{\partial \Phi(\xi^1, \xi^2, \xi^3)}{ \partial \xi ^i} $$

따라서, 다음과 같다.
$$ g_\alpha = a_\alpha - \xi^3 b^\lambda_\alpha a_\lambda , \enspace \alpha = 1,2 \\ g_3 = a_3 $$

## Shell kinematics
shell kinematics의 기본적인 가정은 midsurface에 수직인 직선은 변형후에도 계속 직선을 유지하며 길이가 변하지 않는다는 것이다. 이를 수식으로 나타내면 다음과 같다.
$$ U(\xi^1, \xi^2, \xi^3) = u(\xi^1, \xi^2) + \xi^3 \theta_\lambda(\xi^1, \xi^2) a^\lambda(\xi^1, \xi^2) $$

이 때, $u$는 midsurface의 infinitesimal translational displacement를 나타내며 $\theta_\lambda$는 midsurface에 수직이였던 직선의 infinitesimal rotation을 나타낸다.
