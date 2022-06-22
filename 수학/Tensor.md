# Tensor
As multilinear maps  
using tnesor products



> 참고  
[Tensor - Wiki](https://en.wikipedia.org/wiki/Tensor)  
[텐서 - 나무위키](https://namu.wiki/w/%ED%85%90%EC%84%9C)  
[What are the Differences Between a Matrix and a Tensor? - StackExchange](https://math.stackexchange.com/questions/412423/what-are-the-differences-between-a-matrix-and-a-tensor)  
[텐서 - 전파거북이 블로그](https://ghebook.blogspot.com/2011/06/tensor.html)

# Dyad
$\bf u,v,w$를 벡터라고 하자.
$$ \bf (u \otimes v) \cdot w = u(v \cdot w) $$

위의 관계식을 만족하는 $\bf u \otimes v$를 `dyad`라고 한다. 이 때, $\otimes$를 `텐서곱(tensor product)`이라 한다.

### 명제1
dyad는 선형변환임을 증명하여라.

### 명제2
dyad는 교환법칙이 성립하지 않음을 증명하여라.

### 명제3
$\bf u,v,w,x$를 벡터라고 할 때 다음을 증명하여라.
$$ (\bf (u \otimes v) \cdot w) \otimes x = (u \otimes v) \cdot (w \otimes x) $$

### 명제4
$\bf u,v,w,x$를 벡터라고 할 때 다음을 증명하여라.
$$ \bf (u \otimes v)\cdot(w \otimes x) = (v \cdot w)(u \otimes x) $$

### 명제5
$\bf u,v,w$를 벡터라고 할 때 다음을 증명하여라.
$$ \bf u \cdot (v \otimes w) = (u \cdot v) w $$


# Cartesian Tensor

### 명제1
$\bf I$가 Cartesian Tensor의 Identity tensor라 할 때, 다음을 증명하여라.

$$ \mathbf I = \mathbf e_i \mathbf e_i $$

**Proof**

$\mathbf I = \mathbf e_i \mathbf e_i$라 가정하고 $\bf u$를 임의의 벡터라 하자.

$$ \mathbf{I \cdot u} = u_j (\mathbf e_i \otimes \mathbf e_i) \cdot \mathbf e_j = u_j \delta_{ij} \mathbf e_i = u_i \mathbf e_i \quad {_\blacksquare} $$

### 명제2
$\bf A$가 Cartesian Tensor라 할 때, 다음을 증명하여라.
$$ A_{ij} = (\mathbf A \cdot \mathbf e_j) \cdot \mathbf e_i $$

**Proof**

$$ \mathbf A \cdot \mathbf e_j \cdot \mathbf e_i = A_{kl}((\mathbf e_k \otimes \mathbf e_l) \cdot \mathbf e_j) \cdot \mathbf e_i = A_{kl} \delta_{lj} \delta_{ki} = A_{ij} \quad {_\blacksquare} $$

### 명제3
$\bf A$가 Cartesian Tensor, $\bf x$가 벡터라고 할 때 다음을 증명하여라.
$$ \frac{\partial \mathbf x^T \bf Ax}{\partial \mathbf x} = (\mathbf A^T + \bf A )x  $$

**Proof**  


# Isotropic Tensor
[Isotropic Tensor](https://farside.ph.utexas.edu/teaching/336L/Fluid/node252.html)  
[2nd order isotropic tensor](https://www.weizmann.ac.il/chembiophys/bouchbinder/sites/chemphys.bouchbinder/files/uploads/Courses/2019/TA2-IndexGymnastics.pdf)  
[4th order isotropic tensor](https://math.stackexchange.com/questions/3589647/general-form-of-an-isotropic-fourth-rank-tensor)  