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