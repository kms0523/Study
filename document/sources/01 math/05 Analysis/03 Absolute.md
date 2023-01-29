# Absolute
## 정의
Abelian group $A$가 있다고 하자.

$A$가 totally ordered set일 떄, 절대값 함수 $abs$는 다음과 같이 정의된 함수이다.

$$ abs: A \rightarrow A \st x \mapsto \begin{cases} x & \text{if } 0_A \le x \\ -x & \text{else} \end{cases} $$

### 참고
$abs(a) = |a|$로 표기한다.

### 명제1
다음을 증명하여라.

$$ \forall x \in A, \enspace \forall r \in A^+, \quad |x| \le r \iff -r \le x \le r $$

**Proof**

[$x \le 0$]  
$x \le 0$ 임으로 다음이 성립한다.

$$ |x| \le r \iff -x \le r \iff -r \le x $$

[$0 \le x$]  
$0 \le x$ 임으로 다음이 성립한다.

$$ |x| \le r \iff x \le r $$

[결론]  
따라서 다음이 성립한다.
$$ \forall x \in A, \enspace \forall r \in A^+, \quad |x| \le r \iff -r \le |x| \le r \qed $$

### 명제2(Triangle inequliaty)
다음을 증명하여라.

$$ \forall x,y \in A, \quad |x+y| \le |x| + |y| $$

**Proof**

절대값 함수의 정의에 의해 다음이 성립한다.

$$ \forall x,y \in A, \quad  \begin{gathered} -|x| \le x \le |x| \\ -|y| \le y \le |y| \end{gathered}  $$

따라서, 다음이 성립한다.

$$ -(|x|+|y|) \le x+y \le |x|+|y| $$

명제1에 의해 다음이 성립한다.

$$ |x+y| \le |x|+|y|  $$

#### 따름명제2.1
다음을 증명하여라.

$$ \forall x,y \in A, \quad |x-y| \le |x| + |y| $$

**Proof**

명제2에 의해 다음이 성립한다.

$$ |x-y|=|x+(-y)| \le |x| + |-y| = |x| + |y| \qed $$

#### 따름명제2.2
다음을 증명하여라.

$$ \forall x,y \in A, |x| - |y| \le |x-y| $$

명제2에 의해 다음이 성립한다.

$$ \begin{aligned} |x| &= |x-y+y| \\&\le |x-y|+|y| \\ |x|-|y| &\le |x-y| \qed \end{aligned} $$