# VS Code
## 확장
한국어 패키지  
Markdown All in One

## 단축키
* ctrl , : 설정
* ctrl k + ctrl s : 바로가기 키 설정 
* ctrl + shift + n : 새 vscode창
* ctrl + n : 이름없는 새 파일

## 설정
#### 창의 확대 축소 수준  
설정 >> zoom 검색 >> Window: Zoom Level >> [-1,1]의 값으로 크기 조절

#### 마우스로 편집기 글꼴 확대/축소  
설정 >> zoom 검색 >> Mouse wheel zoom

## 바로가기 키 설정
#### 편집기 간 이동  
* 바로 가기 키 설정 >> "그룹에서 이전 편집기 열기" 검색 >> alt + $\leftarrow$   
* 바로 가기 키 설정 >> "그룹에서 다음 편집기 열기" 검색 >> alt + $\rightarrow$ 
* 바로 가기 키 설정 >> "scrollLineup" 검색 >> alt + $\uparrow$ 
  * "줄 위로 이동" 검색 >> 키 바인딩 제거
* 바로 가기 키 설정 >> "scrollLineDown" 검색 >> alt + $\downarrow$ 
  * "줄 아래로 이동" 검색 >> 키 바인딩 제거

#### 일치항목
* 바로 가기 키 설정 >> 다음 일치 항목 찾기에 선택 항목 추가 >> ctrl + e  
* 바로 가기 키 설정 >> 일치 항목 찾기의 모든 항목 선택 >> ctrl + d  

# Markdown All in One
## 설정
#### css 설정하기
F1 >> 사용자 설정 열기(JSON) >> 아래 내용 입력
```
"markdown.styles": [
    "./css/ms_dark.css"
    ]
```

## 바로가기 키 설정
#### 미리보기 새로 고침 키 설정하기  
F1 >> "미리보기 새로 고침" 검색 >> 톱니바퀴 >> 키 바인딩에 ctrl + R 입력

## 단축키
* ctrl k, ctrl v : 마크다운 미리보기

# Markdwon Preview Enhanced

* preview 화면 우클릭 >> preview theme >> monokai.css

## Customize css
F1 >> Markdwon Preview Enhanced: Customize CSS >> 아래 내용 입력
```
.markdown-preview.markdown-preview 
{
    font-size: 14.5px;     

    h1, h2, h3, h4, h5, h6 
    {        
        color: #e1e1e1;	
    }

    h1	
    {
        margin-top: 80px;
        border-top: 1px solid #e1e1e1;                
        border-bottom: 1px solid #e1e1e1;
        padding: 15px 0px 15px 0px;        
        text-align: center;
        font-size: 40px;
    }
    h2	
    {
        margin: 60px 0px 10px 5px;
        border-left: 8px solid #f79400;
        padding: 0px 0px 0px 10px;        
        font-size: 30px;
    }
    h3	
    {
        margin: 40px 0px 10px 10px;
        border-left: 8px solid #32c97d;
        padding: 0px 0px 0px 10px;        
        font-size: 25px;
    }
    h4	
    {        
        margin: 20px 0px 5px 15px;
        border-left: 8px solid #303F9F;
        padding: 0px 0px 0px 10px;        
        font-size: 20px;
    }
    h5	
    {
        margin: 20px 0px 5px 20px;
        border-left: 8px solid #9f11ac;            
        padding: 0px 0px 0px 10px;        
        font-size: 16px;
    }
    h6	
    {
        font-size: 14px;
    }

    code //inline code
    {
        color: #f3dc95;
        font-size: 14.5px !important;
    }

    pre > code //code block ```
    {
        color: #e1e1e1;	        
        font-size: 14.5px !important;
    }
    
    // blockquote // 인용문 >
    // {
    //     border-top: 1px solid white;
    //     border-bottom: 1px solid white;
    //     border-left-style: hidden;
    //     border-style: hidden;    
    //     padding-left: 10px;
       
    //     background: #292929;
    //     color:#e2e2e2;
    // }
}

```
> Reference
> [stackoverflow - separate-style-for-markdown-in-single-backticks-vs-triple-backticks](https://stackoverflow.com/questions/49703670/separate-style-for-markdown-in-single-backticks-vs-triple-backticks-using-the-m)