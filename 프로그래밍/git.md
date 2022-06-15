# 파일 상태
unstage - stage - commit 공부

### 명령어
* `git restore --staged ./`  
Staging Area에 있는 모든 파일을 다시 unstage

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
* `git branch -u [remote-name]/[branch-name]`  
현재 로컬 브랜치가 리모트 저장소의 특정 브랜치를 추적하게 한다.
* 
# 커밋 되돌리기
### 명령어
* `git commit --amend`  
완료한 커밋을 수정해야 될 때
* `git revert [커밋해시코드]`  
해당 커밋 버전으로 돌아간 상태를 새로 커밋
* `git reset --hard [커밋해시코드]`  
해당 커밋 버전으로 돌아가고 이후의 커밋들을 전부 삭제
* 


