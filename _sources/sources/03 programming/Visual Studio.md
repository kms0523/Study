# Visual Studio
## Map File
`맵 파일(Map File)`은 함수나 변수가 어느 주소에 배치되었는지에 대한 일종의 컴파일 결과 보고서이다.

visual studio에서 Map file을 보고 싶은 경우에는 다음과 같이 하면 된다.

```
프로젝트 >> 속성 >> 링커 >> 디버깅 >> 맵 파일 생성 >> 예
```

이 경우 `project/x64/Debug`에 .map 파일이 생성된다.

> Reference  
> [blog](http://soen.kr/lecture/ccpp/cpp3/31-1-2.htm)
> [blog - map file 읽는법](https://kuaaan.tistory.com/102)

### \$pdata\$, \$unwind\$

> Reference  
> [stackoverflow](https://stackoverflow.com/questions/34609354/how-to-read-dumpbin-for-windows-library-lib)

## Disassembly
디버그 모드 실행 시 다음과 같이 디스 어셈블리 창을 띄울 수 있다.
```
디버그 >> 창 >> 디스 어셈블리
```

## Dumpbin

obj 파일에있는 symbol 결과를 보고 싶으면 VS 2017에 대한 개발자 명령 프롬프트을 실행한 뒤 다음 명령어로 실행한다.

```
cd {file path} 
dumpbin /symbols [filename].obj 
```

symbol 결과를 어떤 파일에 쓰고 싶으면 다음 명령어를 실행하면 된다.
```
dumpbin /symbols [filename].obj > [writefilename].txt
```

### /symbols

> Reference
> [MSDN](https://learn.microsoft.com/ko-kr/cpp/build/reference/symbols?view=msvc-170)

## Clang Format
Clang Format을 사용하기 위해서는 다음 경로로 들어가서 `Clang Format 지원 사용` 옵션을 체크해야 한다.

```
도구 > 옵션 > 텍스트 편집기 > C/C++ > 서식 > 일반 
```

.clang_format 파일은 다음과 같이 추가 할 수 있다.

```
솔루션 탐색기 > 프로젝트 > 추가 > 새항목 > 서식 
```

.clang_format 파일의 수정은 [LLVM-Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)를 참고하면 된다.

### 참고
custom .clang_format을 사용하고 싶은 경우 `사용자 지정 clang-format.exe 파일 사용` 옵션은 체크하지 않아야 한다.

## 솔루션 탐색기
`솔루션 탐색기 >> 파일 우클릭 >> 속성 >> 구성 속성 >> 일반`에 가서 보면 항목 형식에서 cpp 파일이면 `C/C++ 컴파일러`로 되어 있고 h 파일이면 `C/C++ 헤더`로 되어 있다.

## VAssisX

### 문제점
Microsoft Visual Studio Professional 2017 버전 15.9.49와 VA_X.dll file version 10.9.2217.0  built 2017.04.26를 사용하면 multi-catet을 사용해서 typing을 할 때, main caret만 연속해서 글을 쓸 수 있고 나머지 caret들은 한글자만 작성되고 자동 취소된다.

[What's New in Visual Assist](https://www.wholetomato.com/features/whats-new)를 보면 General Release Build 2291에 
```
[VS2017 15.8+] VA no longer interferes with Multi-Caret Edit mode. (case=117499)
```
라고 나와있는것을 확인할 수 있다.

> Reference  
> [forums.wholetomato](https://forums.wholetomato.com/forum/topic.asp?TOPIC_ID=15297)
