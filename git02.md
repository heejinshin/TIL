# git 

## summary

- remote
- clone
- push
- pull
- branch
- switch
- merge



## remote

- remote는 깃허브 repository(이하 remote repo) 와 local directory의 repository를 연결(mapping)시키는 과정이다.

  1. github에 new repository(이하 repo)를 생성한다. 		

  2. 해당 repository의 주소를 복사하여 터미널창에 remote시킨다. 

     ```bash
     $ git remote add origin https://github.com/~
     # origin은 관습적으로 지어주는 name명
     $ git remote -v
     # remote 확인과정
     ```



## clone

- local repo와 remote repo를 연결시킨 후 아무 작업내용을 가지고 있지 않은 local repo에 해주는 초기작업이다. remote repo를 복제해오는 작업. 

   ~~~ bash
   # git폴더에서 작업
   $ git clone https://github.com/~ 
   ~~~

  

## push

- local repo에서 커밋이 끝난 git을 remote repoo에 업데이트 시켜주는 과정이다. 

  ``` bash
  #git폴더에서 작업
  $ git push origin master
  1 + enter
  #github 계정 접근 권한 허용
  # remote repo에 file 업로드 된 것 확인
  
  ```



## pull

- remote repo에서 업데이트된 사항을 local repo로 가져오는 push의 반대 작업이다. 

   ~~~ bash
   $ git pull origin master
   ~~~

  

## branch

- branch는 커밋사항을 기점으로 추가된 분리된 작업영역이다. 프로젝트를 공동 수행하기 위해 각자의 영역에서 작업하기 위한 기능이라고 할 수 있을 것 같다. 

- branch는 포인터다

  ~~~ 
  $ git branchname
  ~~~

- branch는 git 초기 저장소에서 'master'라는 branch를 만들고 커밋을 시작한다. 



## switch

- 현재 branch 위치를 이동한다. 

- branch에서 merge로 현재 위치를 이동하여 merge한다. 

  ~~~ 
  $ git switch branch	
  ~~~



## merge

- 각자 작업하는 branch에서 작업을 완료하면 merge하여 내용을 합친다. 

  ~~~ 
  $ git merge branch
  ~~~



## 기타 노트

- orgin/master 메시지가 빨간색 별개 라인으로 뜨는 것은 remote의 마지막 커밋이 그 위치였다는 뜻이다. 
- 프로젝트 진행시 remote repo에서 readme와 ignore파일을 먼저 만들고 시작하는 것이 좋다. git init명령도 전에. 
- HEAD는 현재 존재하는 위치, 최근 것을 따라간다. 
- git branch graph 명령으로 현재 구조를 확인할 수 있다. 