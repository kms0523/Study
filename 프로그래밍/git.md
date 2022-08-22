# Git Directory
Git이 프로젝트의 메타데이터와 객체 데이터베이스를 저장하는 곳을 말한다. 

Git Directory는 지금 작업하는 디스크 즉, 로컬 데이터베이스에 존재한다.

다른 컴퓨터에 있는 저장소를 Clone 할 때 Git 디렉토리가 만들어진다. 

Git 디렉토리에 있는 파일들은 Committed 상태이다. 

# Working Directory
Working Directory의 모든 파일은 크게 `Tracked(관리대상임)`와 `Untracked(관리대상이 아님)`로 나눈다. 

Tracked 파일은 이미 스냅샷에 포함돼 있던 파일이다. Tracked 파일은 또 `Commited(수정하지 않음)`와 `Modified(수정함)` 그리고 `Staged(커밋으로 Git Directory에 기록할)` 상태 중 하나이다. 

Commited 상태는 Git Directory에 있는 상태에서 수정되지 않았다는 의미이다.

* Committed : 데이터가 로컬 데이터베이스에 안전하게 저장됐다는 것을 의미한다. 
* Modified : 수정한 파일을 아직 로컬 데이터베이스에 커밋하지 않은 것을 말한다.
* Staged : 현재 수정한 파일을 곧 커밋할 것이라고 표시한 상태를 의미한다.


그리고 나머지 파일은 모두 Untracked 파일이다. Untracked 파일은 워킹 디렉토리에 있는 파일 중 스냅샷에도 Staging Area에도 포함되지 않은 파일이다. 

처음 저장소를 Clone 하면 모든 파일은 Tracked이면서 Commited 상태이다. 파일을 Checkout 하고 나서 아무것도 수정하지 않았기 때문에 그렇다.

마지막 커밋 이후 아직 아무것도 수정하지 않은 상태에서 어떤 파일을 수정하면 Git은 그 파일을 Modified 상태로 인식한다. 실제로 커밋을 하기 위해서는 이 수정한 파일을 Staged 상태로 만들고, Staged 상태의 파일을 커밋한다. 이런 라이프사이클을 계속 반복한다.



# 파일 상태
Git은 파일을 `Committed, Modified, Staged` 이렇게 세 가지 상태로 관리한다.


## Git project의 단계
Git으로 하는 일은 기본적으로 아래와 같다.
1. Working Directory에서 파일을 수정한다. 파일은 Modifed 상태가 된다.
2. Staging Area에 파일을 Stage 해서 커밋할 스냅샷을 만든다. 파일은 Staged 상태가 된다.
3. Staging Area에 있는 파일들을 커밋해서 Git 디렉토리에 영구적인 스냅샷으로 저장한다. 파일은 Commited 상태가 된다.

이 때, `Git Directory`, `Working Directory`, `Staging Area`는 다음과 같다.

* Git Directory : 
* Working Directory : 프로젝트의 특정 버전을 Checkout 한 것이다. Git Directory는 지금 작업하는 디스크에 있고 그 Directory 안에 압축된 데이터베이스에서 파일을 가져와서 Working Directory를 만든다.
* Staging Area : Git 디렉토리에 있다. 단순한 파일이고 곧 커밋할 파일에 대한 정보를 저장한다. 종종 “Index” 라고 불리기도 하지만, Staging Area라는 명칭이 표준이 되어가고 있다.


Git 디렉토리에 있는 파일들은 Committed 상태이다. 파일을 수정하고 Staging Area에 추가했다면 Staged이다. 그리고 Checkout 하고 나서 수정했지만, 아직 Staging Area에 추가하지 않았으면 Modified이다.


### 명령어
* `git restore --staged ./`  
Staging Area에 있는 모든 파일을 다시 unstage


# Git 설정

local config file --> 현재 git repository  
global config file --> 모든 git repository

> 참고  
> [블로그 - config file의 구성과 조작](https://kotlinworld.com/302)

### editor 설정
아래를 global config file에 추가하여 vscode를 editor로 설정한다.

```
[core]  
	editor = \"C:\\Users\\김민석\\AppData\\Local\\Programs\\Microsoft VS Code\\bin\\code\" --wait
```

### diff 설정
아래를 global config file에 추가하여 vscode를 difftool로 설정한다.

```
[diff]
    tool = vscode
[difftool "vscode"]
    cmd = code --wait --diff $LOCAL $REMOTE
```

> 참고  
> [블로그 - vscode를 git diff 툴로 활용하기](https://november11tech.tistory.com/168)

### 명령어

* `git config --list`  
  설정 확인
* `git config --global -e`  
  global config file editor로 열기
* `git config --local -e`    
  local config file editor로 열기
* 

# 파일 비교

* `git difftool`  
  diff tool을 이용해서 워킹 디렉토리에 있는 것과 Staging Area에 있는 것을 비교한다. 그래서 수정하고 아직 Stage 하지 않은 것을 보여준다.
* `git difftool --staged`  
  diff tool을 이용해서 저장소에 커밋한 것과 Staging Area에 있는 것을 비교한다.
* 

# 리모트 저장소
리모트 저장소(서버)는 인터넷이나 네트워크 어딘가에 있는 저장소를 말한다. 

다른 사람들과 함께 일한다는 것은 리모트 저장소를 관리하면서 데이터를 거기에 Push 하고 Pull 하는 것이다. 리모트 저장소를 관리한다는 것은 저장소를 추가, 삭제하는 것뿐만 아니라 브랜치를 관리하고 추적할지 말지 등을 관리하는 것을 말한다.

### 명령어

* `git remote`   
현재 프로젝트에 등록된 리모트 저장소를 확인
  * `git remote -v`  
  리모트 저장소의 URL을 확인하는 옵션
* `git remote add [remote name] [url]`   
기존 워킹 디렉토리에 remote name이라는 이름을 갖는 새 리모트 저장소 추가
* `git fetch [remote name]`  
[ref] (Scott Cahcon et al) Pro Git 리모트 브랜치 부분 참고  
로컬에는 없지만, 리모트 저장소에는 있는 데이터를 모두 가져오며 과정은 다음과 같다.  
  1. 리모트 저장소에 로컬의 저장소가 갖고 있지 않은 새로운 정보(커밋, 브랜치)를 모두 내려받는다.
  2. 리모트 저장소의 새로운 브랜치를 받았다면 레퍼런스인 리모트 브랜치를 "remote name/branch name"이라는 이름으로 만든다.
  3. 기존에 리모트 브랜치가 있었던 경우 리모트 브랜치가 최신 커밋을 가르키게 한다.  
* `git remote [old name] [new name]`  
리모트 저장소의 이름을 변경
* `git merge [remote-name]/[branch-name]`

# 브랜치
* `git branch -u [remote-name]/[branch-name]`  
현재 로컬 브랜치가 리모트 저장소의 특정 브랜치를 추적하게 한다.


# 커밋 되돌리기
### 명령어
* `git commit --amend`  
완료한 커밋을 수정해야 될 때
* `git revert [커밋해시코드]`  
해당 커밋 버전으로 돌아간 상태를 새로 커밋
* `git reset --hard [커밋해시코드]`  
해당 커밋 버전으로 돌아가고 이후의 커밋들을 전부 삭제
> 참고  
> Progit >> Git 도구 >> Reset 명확히 알고 가기
* 


