변위기반의 FEM은 변위를 가정하고 $\boldsymbol{\epsilon}$을 변형률-변위 관계식을 통해 구하기 때문에 compatibility condition을 항상 만족한다. 하지만 이렇게 구한 $\boldsymbol{\epsilon}$과 구성방정식 $\boldsymbol {\sigma = E \epsilon}$으로 구한 $\boldsymbol{\sigma}$는 일반적으로 모든 점에서 평형 관계식을 만족하지는 않는다.

반대로 응력기반의 FEM은 모든 점에서 평형 관계식을 만족하도록 stress를 가정하기 때문에 항상 평형 관계식을 만족하지만 이렇게 구한 $\boldsymbol{\sigma}$와 구성방정식 $\boldsymbol {\sigma = E \epsilon}$으로 구한 $\boldsymbol{\epsilon}$는 모든 점에서 compatibility condition을 만족하지 않는다.

# Assumed-stress hybrid element
