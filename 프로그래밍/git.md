# Git Directory
Git Directory는 현재 작업중인 로컬 데이터베이스에 존재하는 저장소로써, 프로젝트의 메타데이터와 객체 데이터를 저장하는 곳이다.

## Staging Area
Git Directory 내부에 있는 영역으로써, 파일을 이곳에 `stage`시킴으로써 `commit`할 `snapshot`을 만든다. 이후에 commit을 통해 Git Directory에 snapshot을 저장한다.

# Working Directory
Working Directory의 모든 파일은 크게 `Tracked(관리대상임)`와 `Untracked(관리대상이 아님)`로 나눈다. 

Tracked 파일은 또 `Commited`(Git Directory의 상태와 동일)와 `Modified`(Git Directory의 상태에서 변경이 발생) 그리고 `Staged`(commit으로 Git Directory에 새롭게 기록 예정) 상태 중 하나이다. 

그리고 나머지 파일은 모두 Untracked 파일이다. 




### 명령어
* `git restore --staged ./`  
Staging Area에 있는 모든 파일을 다시 unstage

* `git rm --cached -r ./`
Traced 파일을 Untracked 파일로 바꿈


# Git 설정
local config file --> 현재 git repository  
global config file --> 모든 git repository

> Reference  
> [블로그 - config file의 구성과 조작](https://kotlinworld.com/302)

### Global 설정
```
[user]
  name = Kim Minseok
  email = rla523at@naver.com
[core]
  editor = \"C:\\Users\\김민석\\AppData\\Local\\Programs\\Microsoft VS Code\\bin\\code\" --wait
[diff]
  tool = vscode
[difftool "vscode"]
  cmd = code --wait --diff $LOCAL $REMOTE
```
* [user] : user 정보 설정
* [core] : vscode를 editor로 설정
* [diff] & [difftool "vscode"] : vscode를 difftool로 설정 

> Reference  
> [블로그 - vscode를 git diff 툴로 활용하기](https://november11tech.tistory.com/168)

### 명령어

* `git config --list`  
  설정 확인
* `git config --global -e`  
  global config file editor로 열기
* `git config --local -e`    
  local config file editor로 열기 

# 파일 비교

* `git difftool`  
  modifed 상태인 파일이 Git Directory에 저장된 snapshot과 어떤 차이가 있는지 diff tool을 이용해서 보여준다.
* `git difftool --staged`  
  staged 상태인 파일이 Git Directory에 저장된 snapshot과 어떤 차이가 있는지 diff tool을 이용해서 보여준다. 

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

# .gitignore

* folder/**
폴더 안에 파일들 전부 무시하기

# Git LFS
> Reference  
> [Blog](https://newsight.tistory.com/330)