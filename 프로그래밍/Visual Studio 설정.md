# 프로젝트 속성
프로젝트 속성에 대한 상세한 내용은 [Windows C++ 프로젝트 속성 페이지 참조 - MSVC](https://docs.microsoft.com/ko-kr/cpp/build/reference/property-pages-visual-cpp?view=msvc-160)에 잘 정리되어 있다.

visual studio에서 프로젝트 속성 탭은 다음 과정으로 열 수 있다.

    보기 >> 다른창 >> 속성 관리자


## 프로젝트 속성 상속하는 법
* http://wanochoi.com/?p=5240

# 외부 DLL 경로 추가하기
* https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sharonichoya&logNo=220817543315
* https://pung77.tistory.com/27
* https://irmxj777.tistory.com/4
* 

# OneAPI
## MPI
* visual studio configuration   
* https://software.intel.com/content/www/us/en/develop/documentation/mpi-developer-guide-windows/top/compiling-and-linking/configuring-a-visual-studio-project.html

## ISSUE
* Environement
  * intel 홈페이지에 나와있는 환경변수가 잘못되어 있음
    * PATH=\$(I_MPI_ONEAPI_ROOT)\bin\\$(ConfigurationName);\$(I_MPI_ONEAPI_ROOT)\libfabric\bin;\$(PATH)
    * ConfigurationName $\rightarrow$ Configuration
  * 인식 못하는 dll 파일이 있는 곳의 위치를 환경변수에 연결해줘야 함
    * PATH=\$(I_MPI_ONEAPI_ROOT)\bin\\$(Configuration);\$(I_MPI_ONEAPI_ROOT)\libfabric\bin;C:\Program Files (x86)\Intel\oneAPI\mkl\2021.4.0\redist\intel64;\$(PATH)


# Google Test
## Initial Setting
1. 기본 속성
2. Test 프로젝트 속성 >> C/C++ >> 미리 컴파일된 헤더 >> 사용안함
3. Main 프로젝트 속성 >> 일반 >> 구성 형식 >> 정적 라이브러리
   1. Main 프로젝트에 main 함수가 포함되어 있어야 정적 라이브러리 생성이 가능

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

# 기본 설정
* 프로젝트 >> 속성 >> 링커 >> 시스템 >> (하위 시스템 , 콘솔 , 콘솔창이 꺼지지 않음)	
*	도구 >> 옵션 >> 텍스트 편집기 >> 모든 언어 >> 스크롤 막대 >> 동작 >> 세로 스크롤 막대에 지도 모드 사용
*	도구 >> 옵션 >> 환경 >> 글꼴 및 색 >> 글꼴 : (JetBrains Mono) >> 색 : 채도를 낮게 해야 보기 편함
*	도구 >> 옵션 >> 텍스트 편집기 >> C/C++ >> 서식 >> 일반 >> ClangFormat 지원 사용 
*	도구 >> 옵션 >> 환경 >> 국가별 설정 >> 언어
*	
  
## 단축키
단축키는 아래 경로를 통해 설정할 수 있다.

    도구 >> 옵션 >> 환경 >> 키보드 >> 단축키

* 정렬 단축키 : ctrl+k+d
* 개요 확장 축소 : ctrl M M
*	개요 전체 확장 축소: ctrl M L
*	개요 전체 삭제 : ctrl M P
* 현재 단어 선택 : ctrl w
* 편집.선택영역을주석으로처리
* 편집.선택영역의주석처리제거

	

[Intellisense 오류시 해결방법]  
	.vs >> codename >> v15 v16 >> ipch 삭제
	
	
[폰트 설치]
	https://wonjjong.tistory.com/27

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



### include
[include 안될 때 stackoverflow](https://stackoverflow.com/questions/39149424/visual-studio-2015-cant-compile-even-hello-world-program)

