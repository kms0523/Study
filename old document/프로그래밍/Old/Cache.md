AIDA64 cache & memory benchmark

[intel i5-11600k 캐시 벤치마크](https://www.thefpsreview.com/2021/12/08/intel-core-i5-12600k-ddr4-alder-lake-cpu-review/6/)

[폰노이만 병목 현상 - Wiki](https://ko.wikipedia.org/wiki/%ED%8F%B0_%EB%85%B8%EC%9D%B4%EB%A7%8C_%EA%B5%AC%EC%A1%B0)

[캐시가 동작하는 아주 구체적인 원리 - 박성범 블로그](https://parksb.github.io/article/29.html)  
[메모리 계층 구조와 성능 - udteam 블로그](https://udteam.tistory.com/202)  
[시스템 캐시란? - 우짱 블로그](https://woozzang.tistory.com/155)  

[CPU 성능](https://wisdom-and-record.tistory.com/4)  
[CPU - 컴퓨터과학특강 - crash course 유투브](https://www.youtube.com/watch?v=FZGugFqdr60&list=PL8dPuuaLjXtNlUrzyH5r6jN9ulIgZBpdo&index=8)

[캐시메모리 - 나무위키](https://namu.wiki/w/%EC%BA%90%EC%8B%9C%20%EB%A9%94%EB%AA%A8%EB%A6%AC)  
[CPU 캐시는 어떻게 작동합니까? - quasar zone](https://quasarzone.com/bbs/qn_hardware/views/818208)

[라이젠은 정말 레이턴시 문제인가? - islands 블로그](https://m.blog.naver.com/vtmbloodline/221717251805)

[Cache Line - 수까락 블로그](http://egloos.zum.com/sweeper/v/2983391)  
[멀티프로세서 환경에서의 CPU 캐시라인 - 웅웅이 블로그](https://jungwoong.tistory.com/42)  
[캐시라인 - 범 블로그](https://seokbeomkim.github.io/posts/cache-line/)

# 캐시

[그림]

위의 그림과 같이 기술의 발전으로 프로세서 속도는 빠르게 증가해온 반면 메모리의 속도는 이를 따라가지 못했다. 프로세서가 아무리 빨라도 계산에 필요한 데이터를 얻기 위해서는 상대적으로 느린 메인메모리에 접근해야 하기 때문에 전체적인 시스템 성능 향상은 메모리 속도에 의한 한계가 있다. 이를 개선하기 위한 장치가 바로 캐시(Cache)다.

캐시는 CPU 칩 안에 들어가는 작고 빠른 메모리다. 프로세서가 매번 메인 메모리에 접근해 데이터를 받아오면 시간이 오래 걸리기 때문에 캐시에 자주 사용하는 데이터를 담아두고, 해당 데이터가 필요할 때 프로세서가 메인 메모리 대신 캐시에 접근하도록해 처리 속도를 높인다.

캐시는 레지스터 다음으로 CPU 코어 가까이에 위치해있다. 캐시는 프로그램에서 직접 읽거나 쓸수 없고, 하드웨어 메모리 관리 시스템에서 내부적으로 제어한다. 따라서 프로그래머가 코드상에서 접근할 수 있는 방법은 없다.

캐시는 CPU와 메인 메모리 사이의 속도 간극을 줄여주는 완충재이며, 따라서 버퍼라고 불리기도 한다. 캐시에는 보통 가격이 비싸고 속도가 빠르지만 용량 대비 크기가 큰 `SRAM(Static Random Access Memory)`을 사용하고, 메인 메모리에는 가격이 싸고 속도가 느린 `DRAM(Dynamic Random Access Meomry)`을 사용한다. 

두 가지의 주요 차이점은 전자는 CMOS 기술과 트랜지스터 (각 블록 당 6 개)로 만들어졌고 후자는 커패시터와 트랜지스터를 사용한다. SRAM은 DRAM의 100배 이상으로 접근 속도가 빠르지만 구조가 복잡하여 공간을 많이 차지하므로 집적도를 높이기 어려워 가격이 비싸고 대용량으로 제작하기가 어렵다.

시스템에 장착된 캐시의 용량과 성능이 점점 증가하면서 캐시의 캐시로 사용되는 메모리가 추가되었다. 이것을 적용된 순서대로 L(Level) 1, L2, L3 ... 라고 호칭한다. L1에 가장 고성능이자 고가인 작은 용량의 집적회로가 사용되고, L1캐시에서 데이터를 퍼가기 위한 캐시로 사용하기 위해 그보다는 용량이 크지만 그 대신 약간 더 느린 저장공간 L2가 추가되었다.

캐시와 메모리는 얼마나 차이가 나는지 아래 간단한 benchmark를 통해 알아보자.

[그림]

먼저 캐시 메모리의 `레이턴시(latency)`란 메모리의 레이턴시는 데이터 요청부터 처리 시작하기까지의 걸리는 시간 이다. 다시말해 메모리의 특정 영역에 접근하는 데 걸리는 시간이고 이로써 캐시 메모리 용량이 클수록 캐시 적중률이 높아지지만 레이턴시가 늘어난다는 단점이 있다.

다음으로 캐시 메모리의 `대역폭(bandwidth)`는 일정 시간 단위의 데이터 처리량으로이다. 즉, 일정한 시간에 얼마만큼의 메모리를 전송할 수 있는지를 나타낸다.

CPU의 사이클은 fetch-decode-execute 순서로 되어있으며 이것을 1 cycle이라고 한다. CPU clock speed는 1초에 몇번의 cycle을 처리할 수 있는지를 나타낸다. 그리고 CPU clock period는 한 cycle을 처리하는데 얼마의 시간이 걸리는지를 나타내고 CPU clock speed의 역수이다. 참고로 명령어의 종류에 따라서 몇 cycle만에 수행이 완료되는지는 다르다.

위의 개념들을 바탕으로 benchmark를 해석해보자. 대략 4GHZ의 CPU clock (speed)임으로 CPU clock period는 0.25ns 정도임을 알 수 있다. 이 떄, L1 cache의 레이턴시는 1.1ns임으로 L1 cache에서 정보를 가져오기 위해서는 대략 4cycle을 돌 수 있는 시간동안 CPU가 기다려야한다. 위의 방식과 같이 다른 부분들을 계산해보면 L2 캐시에서 데이터를 가져오기 위해서는 약 10cycle, L3 캐시에서 데이터를 가져오기 위해서는 약 50cycle, Memory에서 데이터를 가져오기 위해서는 약 250cycle을 기다려야 한다는것을 알 수 있다.

이 간단한 예제만 보더라도 메모리와 캐시의 성능차이가 크다는것을 알 수 있다. 물론 AIDA64 Cache & Memory Benchmark는 엑세스 패턴 구분없이 한 가지 엑세스 패턴을 기준으로만 레이턴시 값을 측정한것이기 때문에 종합적인 latency를 측정한 값이라고 보기는 어렵다. 하지만 캐시의 필요성과 효율성을 알아보기에는 충분한 예시라고 생각한다.

참고로, 캐시 메모리 엑세스 패턴은 캐시 메모리에 담겨진 데이터를 어떤 방식으로 접근하는지를 구분한 개념으로, 엑세스 패턴에 따른 레이턴시 편차가 나타난다. 데이터 지역성에 따라 순차적일수록 캐시 적중률이 높고 레이턴시가 짧지만 랜덤할수록 캐시 적중률이 떨어지고 레이턴시가 길어진다. 현대 프로세서는 레이턴시라는 약점을 감추는 기술이 고도화되어 있기 때문에 한 가지의 엑세스 패턴만으로는 레이턴시를 종합적으로 가늠하기 어렵다.

다음으로는 작은 용량을 가진 캐시가 어떻게 이런 고효율을 낼 수 있는지 그 배경이 되는 원리를 알아보도록 하자.

## 지역성의 원리

'자주 사용하는 데이터’에 관한 판단은 지역성의 원리를 따르며, 지역성 원리는 `시간 지역성(Temporal locality)`과 `공간 지역성(Spatial locality)`으로 구분해서 볼 수 있다.

```cpp
for (i = 0; i < 10; i += 1) 
{
  arr[i] = i;
}
```

시간 지역성은 최근 접근한 데이터에 다시 접근하는 경향을 말한다. 가령 루프에서 인덱스 역할을 하는 변수 i에는 짧은 시간안에 여러 번 접근이 이뤄진다.

공간 지역성은 최근 접근한 데이터의 주변 공간에 다시 접근하는 경향을 말한다. 위 루프의 경우 배열 arr의 각 요소를 참조하면서 가까운 메모리 공간에 연속적으로 접근하고 있다. 배열의 요소들이 메모리 공간에 연속적으로 할당되기 때문이다.

프로세스 실행 중 접근한 데이터의 접근 시점과 메모리 주소를 표시한 아래 그림은 시간 지역성과 공간 지역성의 특성을 잘 
보여준다.

[그림]

위 그림은 페이지를 참조한 기록이다. 가로 축은 실행 시간이고, 세로 축은 메모리 주소다. 즉, 수평으로 이어진 참조 기록은 긴 시간에 걸쳐 같은 메모리 주소를 참조한 것이고, 수직으로 이어진 참조 기록은 같은 시간에 밀접한 메모리 주소들을 참조한 것이다. 페이지에 접근할 때도 지역성 원리가 적용된다는 것을 알 수 있다.

* L1 Cache: 프로세서와 가장 가까운 캐시. 속도를 위해 I\$와 D\$로 나뉜다.
* Instruction Cache (I\$): 메모리의 TEXT 영역 데이터를 다루는 캐시.
* Data Cache (D\$): TEXT 영역을 제외한 모든 데이터를 다루는 캐시.
* L2 Cache: 용량이 큰 캐시. 크기를 위해 L1 캐시처럼 나누지 않는다.
* L3 Cache: 멀티 코어 시스템에서 여러 코어가 공유하는 캐시.


오늘날 CPU 칩의 면적 30~70%는 캐시가 차지한다. 1989년 생산된 싱글 코어 프로세서인 i486의 경우 8KB짜리 I/D 캐시 하나만 있었다. 한편 인텔 코어 i7 쿼드 코어 칩의 다이 맵(Die map)을 보면 4개의 코어에 각각 256KB L2 캐시가 있고, 모든 코어가 공유하는 8MB L3 캐시가 있는 것을 볼 수 있다. (L2 캐시 위에 있는 구역이 L1 캐시로 보이는데, 확실하지 않아서 따로 표시하지 않았다.)

---

대개의 경우 캐시메모리는 메인 메모리에 비해 매우 적은 용량을 갖고 있습니다. 그럼에도 불구하고 적은 용량의 캐시메모리가 CPU와 메모리 사이에서 원활히 가교 역할을 할 수 있는 것은 명령어/데이터 스트림의 '참조 집약성'이라는 성질 때문입니다. 다시 말해 이 성질을 추적함으로써, 캐시메모리는 단지 넓은 메모리 용량 중 일부분을 임의로 저장해 두는 것보다 더 효율적인 방식으로 '필요할 것으로 예측되는' 스트림을 콕 집어 저장해 둘 수 있는 것이죠. 이번 장에서는 이 참조 집약성이란 성질에 대해 알아 보겠습니다.

공간 집약성은 CPU가 메모리상의 어느 한 위치에서 명령어/데이터를 참조했다면 머지 않아 그 근처의 연속된 주소에서 다음 명령어/데이터를 찾는다는 것이고, 시간 집약성은 CPU가 특정 명령어/데이터를 과거에 사용했다면 머지 않은 시간 내에 그 명령어/데이터를 다시 사용한다는 것입니다. 이 참조 집약성은 프로그램에 따라, 그리고 한 프로그램 내에서도 명령어와 데이터에 따라서 달라질 수 있는데, 그 예를 보도록 하죠.

따라서 명령어와 데이터를 별도의 캐시메모리에 나누어 담아 각각 다른 참조 집약성 관리정책을 쓰는 것이 성능상 유리하고, 이렇게 명령어-캐시와 데이터-캐시를 따로 두는 구조를 '하버드 아키텍처'라고 합니다. 오늘날의 CPU에서 L1캐시는 명령어/데이터를 나눠 담는 것이 일반적입니다. (L1-D 캐시, L1-I 캐시)

특정 명령어/데이터 스트림이 시간 집약성이 뛰어나다면 과거에 사용했던 스트림을 항상 저장해 두는 것이 유리하므로 캐시의 용량이 클수록 좋습니다. (반면 캐시의 속도는 그리 중요하지 않게 됩니다) 이와 달리 특정 스트림의 공간 집약성이 뛰어날 때에는, 과거에 사용했던 스트림을 하염없이 저장해 두는 것보다는 메모리상의 연속적인 위치에서 스트림을 '연속적으로' 끊임없이 읽어들이는 것이 중요하므로 캐시의 속도가 빠른 것이 중요합니다. 이 경우엔 과거에 사용했던 스트림이 다시 사용될 가능성이 낮으니 한번 사용된 스트림을 바로 비우더라도 성능에 악영향을 미치지는 않습니다. 따라서 캐시의 용량이 일정 수준 이상 커질 필요는 없죠.


기본적으로, 캐시메모리의 존재 이유는 CPU와 메모리의 속도 차이를 극복하여 CPU에게 '끊김 없이' 스트림을 전달해주기 위해서입니다. ('끊김 없이'가 중요한 이유는 오늘날의 CPU는 상당히 깊은 파이프라인 구조를 사용해, 파이프라인 버블이 성능에 미치는 악영향이 크기 때문입니다)

이론상 고속 & 고용량의 캐시메모리를 장착하면 성능상 가장 좋은 결과를 얻겠지만 비용 문제를 고려했을 때 이는 현명한 해결책이 못 됩니다. 따라서 대부분의 CPU는 초고속/미세용량 - 고속/저용량 - 저속/고용량으로 이어지는 '메모리 계층 구조'를 채택해 각 단계별 속도 차를 세분화함으로써 CPU가 최대한 끊김 없이 스트림을 공급받을 수 있도록 대책을 강구했습니다.

대개 오늘날의 CPU는 CPU - L1 캐시 (명령어/데이터) - L2 캐시 - (L3 캐시) - 메모리로 이어지는 메모리 계층 구조를 갖고 있는데, 첫 장에서 보았던 스크린샷을 다시 한번 보도록 합시다.


가능한 한 속도가 빠른 L1 캐시가 높은 적중률을 갖춰 CPU에게 스트림을 공급해 주는 것이 성능상 가장 유리하기 때문에 용량 대비 L1 캐시의 적중률은 다른 계층보다 훨씬 높게끔 설계됩니다. 하지만 아무리 좋은 정책에 의거해 캐시를 관리하더라도 캐시 미스가 발생하는 경우가 생기는데, L1 캐시에서 캐시 미스가 발생한 경우 CPU는 L2 캐시에게 데이터를 요청하고 L2 캐시가 데이터를 찾게 됩니다. (L2 캐시에서도 미스 발생시 L3 캐시로 넘어가고, 그 다음 순위는 메모리입니다)

이 때 각 계층이 CPU에 응답하는 시간이 레이턴시, 필요한 스트림을 CPU에 전송해 주는 통로의 폭이 대역폭인데 CPU로 넘겨줄 스트림의 용량에 따라 레이턴시와 대역폭이 각각 성능에 미치는 영향력이 달라지게 됩니다. 간단한 예를 들어 보겠습니다.

모든 캐시에서 미스가 발생해 CPU가 메모리에 직접 스트림을 요청했다고 가정해 봅시다.

## 내부구조

캐시 메모리는 S 개의 집합으로 이루어져 있고, 각 집합은 E 개의 캐시 라인을 저장하고 있습니다.

하나의 캐시라인은 메인 메모리에서 가져오는 블록 하나와,  그것이 유효한지 나타내는 유효 비트(Valid bit),

그리고 동일한 집합에 들어올 수 있는 다른 블록들과 구별하기 위한 태그(Tag)를 저장합니다.

따라서 메인 메모리의 각 블록이 B 바이트라고 할 때, 캐시 메모리의 총 사이즈는 (S x B x E) 바이트가 됩니다.

이 때, 세트 당 캐시라인 수 (E) = 1 이면 Direct-Mapped Cache, E > 1 이면 E-way Set Associative Cache 라고 합니다.




## Cache Metrics
캐시의 성능을 측정할 때는 `히트 레이턴시(Hit latency)`와 `미스 레이턴시(Miss latency)`가 중요한 요인으로 꼽힌다.

CPU에서 요청한 데이터가 캐시에 존재하는 경우를 `캐시 히트(Hit)`라고 한다. 히트 레이턴시는 히트가 발생해 캐싱된 데이터를 가져올 때 소요되는 시간을 의미한다. 반면 요청한 데이터가 캐시에 존재하지 않는 경우를 `캐시 미스(Miss)`라고 하며, 미스 레이턴시는 미스가 발생해 상위 캐시에서 데이터를 가져오거나 (L1 캐시에 데이터가 없어서 L2 캐시에서 데이터를 찾는 경우) 메모리에서 데이터를 가져올 때 소요되는 시간을 말한다.

평균 접근 시간(Average access time)은 다음과 같이 구한다:

$$ \text{Miss rate} = {\text{Cache misses} \over \text{Cache acesses}}$$ 
$$ \text{Average access time} = \text{Hit latency} + \text{Miss rate} \times \text{Miss latency }$$

캐시의 성능을 높이기 위해서는 캐시의 크기를 줄여 히트 레이턴시를 줄이거나, 캐시의 크기를 늘려 미스 비율을 줄이거나, 더 빠른 캐시를 이용해 레이턴시를 줄이는 방법이 있다.

## Cache Organization
캐시는 반응 속도가 빠른 `SRAM(Static Random Access Memory)`으로, 주소가 키(Key)로 주어지면 해당 공간에 즉시 접근할 수 있다. 이러한 특성은 `DRAM(Dynamic Random Access Meomry)`에서도 동일하지만 하드웨어 설계상 DRAM은 SRAM보다 느리다. 통상적으로 '메인 메모리’라고 말할 때는 DRAM을 의미한다.

주소가 키로 주어졌을 때 그 공간에 즉시 접근할 수 있다는 것은 캐시가 하드웨어로 구현한 `해시 테이블(hash table)`과 같다는 의미다. 캐시가 빠른 이유는 자주 사용하는 데이터만을 담아두기 때문이기도 하지만, 해시 테이블의 시간 복잡도가 $O(1)$ 정도로 빠르기 때문이기도 하다.

캐시는 블록(Block)으로 구성되어 있다. 각각의 블록은 데이터를 담고 있으며, 주소값을 키로써 접근할 수 있다. 블록의 개수(Blocks)와 블록의 크기(Block size)가 캐시의 크기를 결정한다.

---

CPU의 속도를 나타내는 대표적인 단위는 ‘클럭(clock)’인데, 이는 1초당 CPU 내부에서 몇 단계의 작업이 처리되는 지를 측정해 이를 주파수 단위인 ‘Hz(헤르츠)’로 나타낸 것이다. 따라서, 이 클럭 수치가 높을수록 빠른 성능의 CPU라고 할 수 있다. 참고로, 1971년에 등장한 세계 최초의 컴퓨터 CPU인 ‘인텔(Intel) 4004’의 최대 동작 클럭은 740KHz(74만Hz)였으며, 2010년 현재 판매 중인 CPU인 ‘인텔 코어(Core) i7 960’의 동작 클럭은 3.2GHz(32억Hz)에 달한다.

---

CPU가 메모리로부터 값을 가져올 때는 공간 지역성을 최대화하기 위해 바이트 단위가 아닌, 캐쉬라인 크기만큼 한번에 fetch 한다.

캐쉬라인은 성능을 위해 존재하는데, 보통의 경우 애플리케이션들은 인접한 바이트들을 자주 사용하는 경향이 있다.

만일 인접한 바이트들이 캐시라인에 이미 존재해 있다면, 메모리 버스에 대해 CPU가 추가적으로 접근하게 되는, 비교적 값비싼 행위를 수행할 필요가 없게 된다.

하지만, 멀티프로세서 환경에서는 코어마다 독립된 캐쉬를 가지기에 이것이 마냥 장점으로만 다가 오지만은 않는다.

위와 같은 문제를 해결하기 위해 CPU가 캐쉬라인에 있는 정보를 변경하면, 다른 CPU는 MESI 프로토콜을 통해 이러한 사실을 알아채고, 자신의 캐쉬라인에 있는 정보를 무효화시킨다. (MESI : Modified, Exclusive, Shared, Invalid)
이러한 것들이 하드웨어적으로 보장되며, 이를 cache coherency(일관성)라고 한다.

---

CPU가 메모리로부터 데이터를 가져올 때는 바이트 단위로 가져오지 않고 캐시라인을 가득 채울 만큼의 데이터를 

 가져오는 것을 말합니다. (메모리의 페이징 기법과 비슷합니다.)

 캐시라인의 크기는 32, 64, 128바이트(CPU에 따라 다름) 구성되며 해당 사이즈 경계로 정렬되어 있습니다.

캐시 라인을 사용하는 이유는 일반적인 애플리케이션의 경우 인접한 바이트들을 사용하는 경우가 많기 때문에

 CPU의 메모리 접근 횟수를 줄여 성능을 향상 시키기 위함입니다.

 멀티 프로세서 환경에서 캐시라인
 캐시라인은 성능의 향상을 위해서 도입되었지만 멀티 프로세서 환경에서는 문제가 될 수 있는 여지가 있습니다.

 다수의 CPU가 동일한 캐시라인을 보유하고 있다고 가정하고 그중 하나의 CPU가 해당 캐시라인을 수정한다면

 다른 CPU들은 해당 캐시라인의 갱신을 어떻게 확인 할 수 있을까요?

 이런 문제를 해결하기 위해서 CPU 설계자는 캐시라인이 수정되면 다른 CPU가 들고 있는 캐시라인을 무효화

 시켜 데이터를 동기화 합니다. 이후 다른 CPU는 해당 캐시라인을 사용하려면 메모리에서 다시 읽어야 합니다.  

 이러한 이유 때문에 캐시라인이 오히려 멀티 프로세서 환경에서는 성능을 저해하는 요인이 될 수 있습니다.

---

 프로세서 캐시와 메모리의 불일치 문제는 다루기 까다로운 문제이다. 단순하게 프로세서가 싱글 코어라면 문제가 없겠지만 여러 개의 코어를 가지고 있는 프로세서라면 각각의 코어가 가지고 있는 캐시와 주 메모리를 동기화 시켜주어야 한다. 그러한 동기화로 인해 캐시 성능이 제대로 나오지 않을 것 같은데도 ‘코어 ~ 캐시’의 액세스 속도와 ‘코어 ~ 주 메모리’ 간의 속도 차이가 그러한 동기화 이슈를 가릴 정도로 충분히 크기 때문에 여전히 필자가 보이게 변태같은 구조로 열심히 캐시를 사용하고 있다.

 주 메모리의 내용을 캐시에 저장하기 위해서 주 메모리의 데이터를 읽어와야 한다. 이 때, 읽어들이는 최소 단위를 캐시라인(cahce-line)이라 하며, 이렇게 읽어들인 데이터는 캐시의 data block을 구성하게 된다. 캐시는 아래와 같이 간략하게 나타낼 수 있다.

 메모리 주소의 일부를 이용하여 만든 태그와 해당 캐시라인의 상태(invalid or modified)를 나타내는 상태 비트, 그리고 데이터 블록으로 구성된다. 캐시 정책에 따라 구조가 조금씩 달라지기는 하지만 대략적인 개념은 위와 같으며, 포인트는 메모리의 데이터를 워드 단위가 아닌 “cache-line"의 크기 단위로 읽어들이며, 해당 데이터의 메모리 주소를 이용하여 태그로써 관리한다는 점이다.