# Beam
`보(beam)`는 축 방향에 수직인 하중이 작용해 `굽힘(bending)`을 받아 휘는 부재를 의미한다. 


## 보에 작용하는 응력

보에 작용하는 응력을 다음과 같이 가정하자.

<p align = "center">
<img src = "./image/beam2.png" width = 600>
</p>


가정된 응력으로 발생하는 절단면의 모멘트와 전단력은 다음과 같다.

<p align = "center">
<img src = "./image/beam3.png" width = 600>
</p>


`보 요소(beam element)`는 1차원 요소로 봉과 다르게 축방향, `횡방향(lateral)`, `비틀림(twisting)` 하중이 작용하는 경우이다.

단면에 발생하는 모멘트는 normal stress의 분포 때문이다.