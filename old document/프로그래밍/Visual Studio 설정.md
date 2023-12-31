# 기본 설정
* 프로젝트 >> 속성 >> 링커 >> 시스템 >> (하위 시스템 , 콘솔 , 콘솔창이 꺼지지 않음)	
*	도구 >> 옵션 >> 텍스트 편집기 >> 모든 언어 >> 스크롤 막대 >> 동작 >> 세로 스크롤 막대에 지도 모드 사용
*	도구 >> 옵션 >> 환경 >> 글꼴 및 색 >> 글꼴 : (JetBrains Mono) >> 색 : 채도를 낮게 해야 보기 편함
*	도구 >> 옵션 >> 텍스트 편집기 >> C/C++ >> 서식 >> 일반 >> ClangFormat 지원 사용 
*	도구 >> 옵션 >> 환경 >> 국가별 설정 >> 언어	
  
## 단축키
단축키는 아래 경로를 통해 설정할 수 있다.

    도구 >> 옵션 >> 환경 >> 키보드 >> 단축키

* 검색 : ctrl + q
* 창.문서창닫기 : ctrl + w
  * 편집.현재단어선택 >> 선택한 명령의 바로가기 제거
* 창,다음문서창으로 이동 : ctrl + tab
* 창.이전탭 : alt + $\leftarrow$
* 창.다음탭 : alt + $\rightarrow$ 
* 편집.아래로줄스크롤 >> alt + $\downarrow$
  * 편집.선택한줄아래로이동 >> 제거
* 편집.위로줄스크롤 >> alt + $\uparrow$
  * 편집.선택한줄위로이동 >> 제거
* 편집.한줄아래까지열확장선택 >> ctrl + alt + $\downarrow$
* 편집.한줄위까지열확장선택 >> ctrl + alt + $\uparrow$ 
* 편집.문서서식(정렬) : ctrl + k, ctrl + d
* 편집.선택영역을주석으로처리 >> ctrl + /, ctrl +/
* 편집.선택영역의주석처리제거 >> alt + /, alt +/
* 개요 확장 축소 : ctrl M M
* 개요 전체 확장 축소: ctrl M L
* 개요 전체 삭제 : ctrl M P


	

[Intellisense 오류시 해결방법]  
	.vs >> codename >> v15 v16 >> ipch 삭제
	
	
[폰트 설치]
	https://wonjjong.tistory.com/27

# 프로젝트 속성
프로젝트 속성에 대한 상세한 내용은 [Windows C++ 프로젝트 속성 페이지 참조 - MSVC](https://docs.microsoft.com/ko-kr/cpp/build/reference/property-pages-visual-cpp?view=msvc-160)에 잘 정리되어 있다.

visual studio에서 프로젝트 속성 탭은 다음 과정으로 열 수 있다.

    보기 >> 다른창 >> 속성 관리자

## 디버깅
#### 환경
dll 참조 path를 추가해준다.
```
PATH=경로;%PATH%
```

> Reference  
> [Blog - 외부 DLL 경로 추가하기](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sharonichoya&logNo=220817543315)

* https://pung77.tistory.com/27
* https://irmxj777.tistory.com/4

## 링커
### 일반
#### 추가 라이브러리 디렉터리
사용자가 환경의 라이브러리 경로를 재정의할 수 있다. (/LIBPATH:folder) 즉, 여기서 .lib 파일을 찾아볼 디렉터리를 관리한다.

### 입력
#### 추가종속성
링크 명령줄에 추가할 추가 항목(예: kernel32.lib)을 지정한다. 즉, 여기서 링크시 찾아 볼 .lib 파일의 목록을 관리한다.

> Reference  
> [MSDN - linker property pages](https://docs.microsoft.com/ko-kr/cpp/build/reference/linker-property-pages?view=msvc-160)

## 프로젝트 속성 상속하는 법
* http://wanochoi.com/?p=5240



# Google Test
## Initial Setting
1. 테스트 프로젝트 구성  
테스트할 프로젝트 선택하고 나머지는 아래와 같이 설정한다.

<p align = "center">
<img src = "./image/GTEST1.png" width = 500>
</p>

2. Test 프로젝트 속성 >> C/C++ >> 미리 컴파일된 헤더 >> 사용안함
3. Main 프로젝트 속성 >> 일반 >> 구성 형식 >> 정적 라이브러리
   1. Main 프로젝트에 main 함수가 포함되어 있어야 정적 라이브러리 생성이 가능
4. Solution 속성 >> 공용 속성 >> 시작 프로젝트 >> 현재 선택 영역

### 참고
[블로그](https://two-parks.tistory.com/36)  

## Document
https://github.com/google/googletest/blob/master/docs/primer.md
https://github.com/google/googletest/blob/master/docs/advanced.md

## ISSUE
* LNK2019 error include header file instead of cpp file
  * https://stackoverflow.com/questions/43413180/google-tests-dont-work-with-class-in-other-project-in-solution
  * https://zepeh.tistory.com/466
  * https://www.javaer101.com/en/article/12126422.html

* /GL로 컴파일한 MSIL .netmodule 또는 모듈이 있습니다. /LTCG를 지정하여 링크를 다시 시작하십시오. /LTCG를 링크 명령줄에 추가하면 링커 성능이 향상됩니다.
  * https://kldp.org/node/122696  
  * https://docs.microsoft.com/ko-kr/cpp/build/reference/ltcg-link-time-code-generation?view=msvc-160  
  * https://yonjh.tistory.com/116  

### MKL Library 사용

#### mkl_sequential.1.dll이 없어 코드 실행을 진행할 수 없습니다.
Test 프로젝트 >> 속성 >> Intel Libraries for oneAPI >> Use one MKL >> Sequential

#### warning LNK4006
기존 프로젝트 >> 속성 >> 라이브러리관리자 >> 명령줄 >> /IGNORE:4006 

Q1. 프로젝트에 DLL을 연결한다는 것이 어떤 의미인지  
Q2. DLL을 사용하는 프로젝트를 테스트하려면 어떻게 해야하는지?

##### 참고
[Link libraries with dependencies in Visual C++ without getting LNK4006 - StackOverFlow](https://stackoverflow.com/questions/564872/link-libraries-with-dependencies-in-visual-c-without-getting-lnk4006)  
[How to test an EXE with Google Test? - StackOverFlow](https://stackoverflow.com/questions/23088252/how-to-test-an-exe-with-google-test)  

# SDK 
`소프트웨어 개발 도구(Software Development Kit; SDK)`은 주로 코드를 프로그램으로 빌드하는 과정에서 사용되는 보조 도구이다.

SDK 버전 오류는 크게 두가지 방법으로 해결 할 수 있다.

1. 현재 개발 환경에 설치된 SDK 버전에 맞게 해당 프로젝트의 SDK 버전을 바꿔서 설정해준다.
2. 현재 개발 환경의 SDK 버전을 해당 프로젝트의 SDK 버전에 맞게 업데이트해준다.


## 2번 해결 방법
[MSVC의 아카이브](https://developer.microsoft.com/ko-kr/windows/downloads/sdk-archive/)에서 필요한 SDK 버전을 찾고 Install SDK를 클릭한다.

다운로드 된 파일을 실행시키고 현재 컴퓨터의 common installation path에 SDK버전을 설치한다.

<p align= "center">
<img src = "./image/SDK1.png" width = 600>
</p>

설치 후 컴퓨터를 재시작하고 visual studio에서 프로젝트를 연다음에 아래와 같은 과정을 거쳐 필요한 SDK 버전으로 바꾼다.

    솔루션 탐색기 >> 솔루션 오른쪽 마우스 >> 솔루션 대상 변경 >> Windows SDK 버전 >> 다운로드 받은 버전 선택

Q. installation path에서 지우면 지워질까?  

### 설치 후에도 인식되지 않을 때
Design time folder가 있는지 확인하기

[stackoverflow](https://stackoverflow.com/questions/43704734/how-to-fix-the-error-windows-sdk-version-8-1-was-not-found)  
[MSDN](https://social.msdn.microsoft.com/Forums/office/en-US/5287c51b-46d0-4a79-baad-ddde36af4885/visual-studio-cant-find-windows-81-sdk-when-trying-to-build-vs2015?forum=visualstudiogeneral)  

## 참고
[매화 블로그](https://mewha.tistory.com/12)  
[Windows SDK and emulator archive - MSVC](https://developer.microsoft.com/ko-kr/windows/downloads/sdk-archive/)

# 플랫폼도구집합
    프로젝트 >> 속성 >> 일반 >> 플랫폼 도구 집합

## 참고
[HwanShell 블로그](https://hwan-shell.tistory.com/137)

# visual studio 2015
## 설치 경로

    C:\Program Files (x86)\Microsoft Visual Studio 14.0

# 에러
#### SDK 8.1 문제
SDK 관련 문제가 발생하여 [MSVC의 아카이브](https://developer.microsoft.com/ko-kr/windows/downloads/sdk-archive/)에서 필요한 SDK 버전을 다운로드 받아서 설치를 하였지만 계속 인식하지 못하는 문제가 발생하였다. 이는 경로 설정등에 문제가 아니라 설치가 잘못 되어 필요한 파일이 없어서 발생한 오류였다. 

SDK 8.1을 설치하기 위해 visual studio 2015를 설치하였고 정상적으로 설치된 SDK는 개발환경구축 폴더에 저장해두었다.

아래는 정상적으로 다운로드된 8.1 폴더의 구성이다.

<p align = "center">
<img src = "./image/issue1.png" width = 600>
</p>

`C:\Program Files (x86)\Windows Kits` 경로에 8.1 폴더가 있는지, 8.1 폴더안이 위의 구성과 같은지 확인해보면 SDK 설치가 제대로 되었는지 알 수 있다.

#### C1083 corecrt.h 관련 문제
visual studio 2015를 제거를 강제로 중지하였더니 특정 파일이 제대로 지워지지 않았거나, 아직 작업중인 상태였는데 바로 재설치를 진행하였더니 필요한 특정 파일들이 설치가 제대로 되지 않아 문제가 발생하였다.

visual sutdio 2015 제거중에 강제로 중지하지 않고 기다리고, 제거 후에 재부팅 하고 재설치를 진행하니 문제가 해결되었다.