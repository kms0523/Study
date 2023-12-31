# Virtual Memory
가상 메모리는 "프로세스가 실행 될 때 프로세스 전체가 주기억장치에 올라와 있을 필요가 없다"는 점을 활용한 메모리 관리 기법이다.

메모리 접근은 순차적이고 지역적이기 때문에 명령어 수행에 필요한 메모리는 전체 프로세스에 필요한 용량에 비해 훨씬 작다. 단독 기계 명령어를 실행하기 위해서는 다음 3가지의 메모리 접근이 필요하다.

* 메모리에서 명령어 읽기
* 메모리에서 명령어를 수행하는데 필요한 데이터 읽기
* 명령어 수행 후  결과를 메모리에 기록

매번 메모리에 접근하는데 필요한 실제 바이트 수는 CPU 아키텍쳐 및 실제 명령어와 데이터 유형에 따라 달라진다.  그러나 예를 들어 각 메모리 접근 유형마다 100 바이트의 메모리가 필요하다고 가정하면 위의 경우 300 바이트만 메모리에 올라와 있어도 명령어를 수행할 수 있다.

이런 순차적이고 지역적인 특성을 활용하면 전체 프로세스에 필요한 용량이 아닌 명령어 수행에 필요한 최소 메모리만 주기억장치에 있고 나머지는 보조 기억 장치에 위치해도 프로그램을 실행할 수 있다. 결국 빠르고 작은 주기억장치를 크고 느린 보조기억장치와 병합하여 하나의 크고 빠른 기억장치(가상 메모리)처럼 동작하게 한다.

가상 메모리를 사용하고 프로그램 실행에 필요한 만큼만 주기억장치에 올리기로 결정했다고 가정하자. 이 경우, 주기억장치에 올리고 내리고 하는 데이터의 크기가 모두 제각각이므로 필연적으로 `단편화(fragmentation)`가 발생하게 된다. 결국 주기억장치에 공간은 남아 있지만 정작 원하는 크기의 데이터를 로드하지 못하게 되는 상황이 생길 수 있는 것이다. 이런 경우를 `외부 단편화(external fragmentation)`라고 한다.

이를 해결하기 위해 운영체제가 만든 것이 `페이지(page)`라는 최소 크기 단위이며 이를 활용하여 메모리를 다루는 시스템을 `페이지 시스템(paging system)`이라고 한다.

> Reference  
{cite}`FundamentalC++`  
[가상 메모리 - ahanne 블로그](https://ahnanne.tistory.com/15)  
[가상 메모리 - 채니 블로그](https://mimimimamimimo.tistory.com/29)  