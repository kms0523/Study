# Internal Loading
물체에 외력이 가해질 경우, 물체는 이를 견디기 위해 내부에 `내부력(internal loading)`이 발생한다.

# Method of Section
물체에 작용하는 internal loading을 결정하기 위해서 `method of section`을 사용할 수 있다.

다음과 같은 2차원 beam element를 가정하고 B면에 작용하는 internal loading을 알아보자.
<p align = "center">
<img src = "./image/internal loading1.png">
</p>

B면을 지나가는 단면으로 물체를 둘로 나누고 두 물체에 대한 free-body diagram을 작성한다.

<p align = "center">
<img src = "./image/internal loading2.png">
</p>

이 과정에서 단면에 의해 나뉜 두 물체에서는 B면의 내부력이 외부력이 되어, 나뉜 물체의 free-body diagram에 들어나게 된다.

### 참고1
2차원의 경우 잘린 단면에서 3개의 internal loading을 갖으며, 2개의 force와 1개의 couple moement로 구성되어 있다.

### 참고2
Newton의 제 3 운동법칙에 의해, 잘린 단면에서 두 물체의 internal loading은 크기는 같고 방향은 서로 반대여야 한다.

# Internal Loading Resultant
2차원과 3차원 beam element에서 internal loading은 다음과 같다.
<p align = "center">
<img src = "./image/internal loading3.png">
</p>

2차원에서 각각의 internal loading은 다음과 같이 구성되어 있다.
* $N_x$ : normal force
* $V_y$ : shear force 
* $M_x$ : bending moement

3차원에서 각각의 internal loading은 다음과 같이 구성되어 있다.
* $N_y$ : normal force
* $V_x, V_z$ : shear force
* $M_x, M_z$ : bending moement
* $M_y$ :  tortion(twisting) moment

### 참고
위와 같은 internal loading을 $+$로 보는 sign convention을 사용한다.