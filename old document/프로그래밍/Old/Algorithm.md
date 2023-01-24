# 그래프

방향 그래프 : Edge에 방향성이 주어져 있는 경우

무방향 그래프 : Edge에 방향성이 주어져 있지 않는 경우

# 다익스트라
[다익스트라 개념](https://yabmoons.tistory.com/364)

[priority queue 개념](https://chanhuiseok.github.io/posts/ds-4/)  
[priority queue 사용법](https://chanhuiseok.github.io/posts/algo-54/)  
[priority queue vs set](https://stackoverflow.com/questions/10141841/difference-between-stdset-and-stdpriority-queue)

# 유클리디안 호제법(Euclidean Alogirthm)
두 양의 정수 $a,b(a > b)$에 대해 $a = bq +r$이라 하면,

$gcd(a,b)=gcd(b,r)$이다.

$gcd := \text{greatest common division}$

#### Proof

$gcd(a,b) = g_1, gcd(b,r) = g_2$라 하자.

그러면 적당한 서로소 $k_1,k_2$에 대해 $a=g_1k_1, b=g_1k_2$가 성립한다.

이를 대입하여 정리하면 $r=g_1(k_1-qk_2)$이 된다.

따라서 $g_1$은 $b,r$의 공약수이고 $gcd(b,r) = g_2$ 임으로 $g_2 = mg_1$으로 표현할 수 있다.

마찬가지로 적당한 서로소 $k_3,k_4$에 대해 $b=g_2k_3, r=g_2k_4$가 성립한다.

이 떄, $b = g_1k_2 = g_2k_3 = mg_1k_3 \rightarrow k_2 = mk_3$ 이고

$r = g_1(k_1-qk_2) = g_2k_4 = mg_1k_4 \rightarrow k_1-qk_2 = mk_4$ 이다.

윗 식을 아랫식에 대입하면 $k_1 = m(k_3q + k_4)$ 이다.

즉 $m$은 $k_1,k_2$의 공약수이며 서로소 가정에 의해 $m=1$이다.


### $2$진수 $\rightarrow$ $2^n$ 진수 변환
임의의 수를 2진수로 나타내면 다음과 같다.

$$ \cdots a_i \cdots a_0 \ _{(2)} = \sum_{i=0}^m a_i2^i $$

이를 n자리씩 끊은뒤 $(2^n)^k$로 묶으면

$$ \cdots (a_{nk + n - 1} \cdots a_{nk})_k \cdots  (a_{n-1} \cdots a_0)_0  = \sum_{k=0}^m (a_{nk+ n - 1} \cdots a_{nk}) (2^n)^k $$

이를 $2^n$ 진수로나 나타내면

$$ \sum_{k=0}^m b_k(2^n)^k $$
$$ b_k = a_{nk+ n - 1} \cdots a_{nk} $$

$2^n$진수 $\rightarrow$ $2$ 진수 변환은 반대로 해주면 된다.