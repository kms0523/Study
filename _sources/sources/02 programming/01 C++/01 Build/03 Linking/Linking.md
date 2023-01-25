# Linking
마지막으로 링킹 단계에서는 컴파일러가 생성한 목적 파일들과 외부 라이브러리 파일들을 모아서 실행 파일을 생성한다.

링크란 수많은 목적 코드들이 프로세스 메모리 가상 공간에 적재되었을 때 서로가 맞물릴 수 있도록 각각의 주소를 변경해주는 것을 의미한다.

이 링킹 과정이 끝나게 되면 사용하는 시스템에 따라서 각기 다른 형식으로 파일들을 생성하게 된다. 윈도우즈 계열의 시스템의 경우 `portable executable (PE)`이라 불리는 PE 형식으로 실행 파일을 생성하고, 리눅스 계열의 시스템의 경우 `executable and linkable format (ELF)`이라 불리는 ELF 형식으로 실행 파일을 생성한다.

이 두 실행 파일은 파일 형식이 다르기 때문에 같은 코드를 컴파일 하더라도 윈도우즈의 PE 파일을 리눅스에서 일반적으로 실행할 수 없고, 반대로 윈도우즈에서 리눅스의 ELF 파일을 실행할 수 없다.

링킹 과정에서 목적 코드들에 정의된 심볼들 (함수들이나 객체들)의 위치를 확정 시킨다. 이 때 C++에서 심볼들의 위치들을 정할 때 어떠한 방식으로 정할지 알려주는 키워들이 있는데 이를 `저장 방식 지정자 (storage class specifier)`라고 한다.