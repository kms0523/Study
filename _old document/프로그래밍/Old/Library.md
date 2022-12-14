# Library

## 라이브러리 배포

### Cmake

### Header only library
#### Pros and Cons
> Reference
> [stackoverflow](https://stackoverflow.com/questions/12671383/benefits-of-header-only-libraries)

## Static Library

> Reference    
> [external library 사용법](https://gnueskob.github.io/editor/2019/08/11/external-lib.html)  
> [compiling-a-library-that-uses-another-library-in-c - stackoverflow](https://stackoverflow.com/questions/41322971/compiling-a-library-that-uses-another-library-in-c)  
> [creating-and-using-a-static-library - MSDN](https://docs.microsoft.com/en-us/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-170)  
> [create-a-c-library-that-links-another-library-but-doesnt-depend-on-its - stackoverflow](https://stackoverflow.com/questions/36665221/can-i-create-a-c-library-that-links-another-library-but-doesnt-depend-on-its-i)  
> [visual studio 정적 동적 라이브러리 만들기](https://www.vbflash.net/193)  

## 외부 DLL 경로 추가하기
* https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sharonichoya&logNo=220817543315
* https://pung77.tistory.com/27
* https://irmxj777.tistory.com/4

## 프로젝트 속성
프로젝트 속성에 대한 상세한 내용은 [Windows C++ 프로젝트 속성 페이지 참조 - MSVC](https://docs.microsoft.com/ko-kr/cpp/build/reference/property-pages-visual-cpp?view=msvc-160)에 잘 정리되어 있다.

visual studio에서 프로젝트 속성 탭은 다음 과정으로 열 수 있다.

    보기 >> 다른창 >> 속성 관리자

### 링커

#### 일반
##### 추가 라이브러리 디렉터리
사용자가 환경의 라이브러리 경로를 재정의할 수 있다. (/LIBPATH:folder) 즉, 여기서 .lib 파일을 찾아볼 디렉터리를 관리한다.

#### 입력
##### 추가종속성
링크 명령줄에 추가할 추가 항목(예: kernel32.lib)을 지정한다. 즉, 여기서 링크시 찾아 볼 .lib 파일의 목록을 관리한다.

> 참고  
> [linker property pages - MSDN](https://docs.microsoft.com/ko-kr/cpp/build/reference/linker-property-pages?view=msvc-160)

### 프로젝트 속성 상속하는 법
* http://wanochoi.com/?p=5240

## 외부 DLL 경로 추가하기
```
PATH=경로;%PATH%
```

* https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sharonichoya&logNo=220817543315
* https://pung77.tistory.com/27
* https://irmxj777.tistory.com/4


