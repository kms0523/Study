# 폴더구성법
문서들은 sources 폴더안에 구조를 갖춰서 저장한다.

sources 내부에 폴더 구성을 어떻게 하냐에 따라 페이지 왼쪽에 나타나는 TOC(table of contents)가 달라진다.

아래 예시를 통해 폴더 구성과 TOC의 관계를 확인해보자.

폴더 구성이 다음과 같이 되어 있다고 하자.

```
sources
│
├─Chapter1
│  │  document1.md
│  │  document2.md
│  │  zebra.md
│  │
│  └─section
│      │  related1.md
│      │  related2.md
│      │  section.md
│      │
│      └─section in section
│              related1.md
│              section in section.md
│
├─Chapter2
│      document1.md
```

이 경우 TOC는 다음과 같이 구성된다.

```{figure} _image/toc.png
```

## 주의사항1
section 폴더 안에는 section 이름과 동일한 .md 파일이 반드시 존재해야된다.

위 예시에서도 section 폴더안에 `section.md` 파일이 section in section 폴더안에 `section in section.md` 파일이 존재하는걸 볼 수 있다.

`section.md` 파일은 아래와 같이 TOC에서 section을 눌렀을 때 나타날 페이지 이다.
```{figure} _image/section.png
```

## 주의사항2
파일이 하나만 있는 경우 section 폴더로 만들지 않는다.

아래와 같이 section 안에 section.md만 있는 경우를 생각해보자.
```
(bad example)

├─section
│  │  section.md
│
│  document1.md
│  document2.md
```

이 경우에는 다음과 같이 폴더를 구성을 해야 한다.

```
(good example)

│  section.md
│  document1.md
│  document2.md
```

## 주의사항3
TOC에 표시되는 이름들은 .md파일의 파일명으로 생성되는것이 아니다.

TOC는 .md파일 안에 있는 H1 header(#)의 이름으로 생성이 된다.

section의 이름은 `section.md` 파일 안에 있는 H1 header의 이름으로 생성된다.

### Example1
현재 document1.md파일은 다음과 같다.
```
document1.md

# document1.md
```

만약 document1.md의 내용을 다음과 같이 바꿨다고 가정해보자
```
document1.md

# document123.md
```

그러면 TOC에는 document123으로 표시된다.


## 주의사항4
TOC에 표시되는 순서는 파일명 alphabet 순서로 생성된다.

### Example
현재 파일이 다음과 같다고 해보자
```
document1.md

# document1.md

--------------------

document2.md

# document2.md
```

그러면 TOC는 다음과 같이 구성된다
```
document1
document2
```

이 떄 내용을 다음과 같이 바꾼다고 해보자
```
document1.md

# document99.md

--------------------

document2.md

# document2.md
```

그러면 TOC는 다음과 같이 구성된다
```
document99
document2
```



