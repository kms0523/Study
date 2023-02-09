# Inequality

## AM-GM inequality
$x,y \in \R$일 떄, 다음을 증명하여라.

$$ 2\sqrt{|x||y|} \le |x|+|y| $$

**Proof**

$$ \begin{aligned} 0 &\le (|x|-|y|)^2 \\&\le (|x|+|y|)-4|x||y| \\ 4|x||y| &\le (|x|+|y|)^2 \\ 2\sqrt{(|x||y|)} &\le |x| + |y| \qed \end{aligned} $$

## Triangle inequliaty
다음을 증명하여라.

$$ \forall x,y \in A, \quad |x+y| \le |x| + |y| $$

**Proof**

절대값 함수의 정의에 의해 다음이 성립한다.

$$ \forall x,y \in A, \quad  \begin{gathered} -|x| \le x \le |x| \\ -|y| \le y \le |y| \end{gathered}  $$

따라서, 다음이 성립한다.

$$ -(|x|+|y|) \le x+y \le |x|+|y| $$

명제1에 의해 다음이 성립한다.

$$ |x+y| \le |x|+|y|  $$

### 따름명제1
다음을 증명하여라.

$$ \forall x,y \in A, \quad |x-y| \le |x| + |y| $$

**Proof**

Triangle inequliaty에 의해 다음이 성립한다.

$$ |x-y|=|x+(-y)| \le |x| + |-y| = |x| + |y| \qed $$

### 따름명제2
다음을 증명하여라.

$$ \forall x,y \in A, |x| - |y| \le |x-y| $$

Triangle inequliaty에 의해 다음이 성립한다.

$$ \begin{aligned} |x| &= |x-y+y| \\&\le |x-y|+|y| \\ |x|-|y| &\le |x-y| \qed \end{aligned} $$

## noname1

$x,y \in \R$일 떄, 다음을 증명하여라

$$ |x|+|y| \le \sqrt{2(x^2 + y^2)} $$

**Proof**

$$ \begin{aligned} 0 &\le (|x|-|y|)^2 \\ (|x|+|y|)^2 &\le (|x|-|y|)^2 + (|x|+|y|)^2 \\ |x|+|y| &\le \sqrt{2(|x|^2+|y|^2)} \qed \end{aligned} $$


> Reference
> [wiki](https://en.wikipedia.org/wiki/Inequality_of_arithmetic_and_geometric_means)