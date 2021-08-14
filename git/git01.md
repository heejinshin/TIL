# :pen: git

- git과 git허브
  - 정의
  - 오픈소스의 활용
- git bash사용하기 
  - 프로그램 알기
  - 주요 명령어



## git과 github

- 정의 

  -  git이란, 소스 버전 관리 시스템이고  github는 그걸 모아놓은 저장소이다. 파일을 저장할 때 같은 내용이 중복되어 저장되면 용량이 비효율적으로 늘어나기 때문에 소스의 변경사항만 저장해나가면서 트래킹할 수 있다. git이 스마트폰의 사진들을 관리하는 갤러리라면 github는 드라이브 같은 개념이라고 할 수 있다. 

    https://git-scm.com/book/ko/v2.  : git 공식문서

- 오픈소스의 활용

  - git을 알기 전에 4차산업 혁명에 있어 기술이 우리 삶을 얼마나 바꾸고 있는지 생각해 볼 수 있었다. 또 내가 얼마만큼 관심을 가지고 있었는지도,  지금까지는, '4차산업'이라는 용어는 취업뉴스 헤드라인에서나 떠올려볼 수 있었다. 다양한 인터페이스의 사용, 소프트웨어 발전에 있어서 오픈소스에 관심 갖고 적용해보기 위해 깃허브의 오픈소스를 사용해 볼 줄 알아야 한다. 프로젝트를 쌓아가며 내 문서를 오픈소스화 해보자. 

- git은 file에 변경사항이 조금이라도 생기면 바로 알아채는 세심한 관리 시스템이다. git폴더 옆에 cctv가 있다고 생각하고 git을 생성한뒤 다음에 진행되는 과정들을 추적할 수 있게 등록하고 움직인 것들을 스냅샷 찍어나가는 과정이라 떠올려 보면 이해가 쉽다. 

## git bash 프로그램 알기 

- 들어가기 전에, git bash란
  - Git bash는 born again shell, 쉘 또는 터미널이라고 할 수 있다. 이는 CLI인데 Command line Interface이다. 비교 대상으로 GUI는 Graphic User Interface로 사용자가 쉽게 쓰도록 만든 그래픽 인터페이스이다.
  - 윈도우 directory창과 bash 터미널창을 같이 띄워놓고 gui방식을 통해 directory의 구조를 살펴볼 수 있었다.
    - C드라이브 > 내계정 dir(home폴더) > 하위 폴더들   

## git bash 주요 명령어

### 	git init 

- 개념: directory를 repository로 업그레이드 하는 작업. git repository(.git) 생성, git폴더는 눈에 보이지 않지만 bash창에서 확인 가능하다. 

  ~~~ bash
  $ ls -a
  ./  ../   .git/
  ~~~

   .은 현재 위치이고 ..은 상위directory이다. 

  - git의 위치를 working directory 또는 working tree라고 한다. 

- 사용방법

  ~~~ 
  $ git init
  ~~~

  - bash창에서 명령어는 $ sign이 떠있을때 입력한다. 
  - 명령을 내리기 전에 위치를 확인해주어야 하는데, 홈폴더를 repository(이하 repo)화 하면 안된다. 그 이유는 repo안에 repo가 생기면 안되는데 우리는 home폴더 하위에 위치한 작업폴더를 repo해줄 것이기 때문이다. 명령 라인에 떠있는 현재 위치가 ~(home)상태인지 꼭 확인하고 init을 하자, 잘못했을 경우에는 home에 생긴 git을 삭제하는 작업을 해야한다. 

### 	git add

- 개념: 수정된 소스 파일을 새로운 버전화 하기 이전에 그 대기목록에 올려두기 위함이다. 이를 staging 단계라 한다. stage에 내가 manage할  file들을 대기시켜 두는 것이다. file 수정 사항이 있다면 반드시 이 단계를 거쳐야 한다. 

- 사용방법  

  ~~~ bash
  $ git add <filename>
  ~~~

    ### git commit

- 개념 : stage에 올라와있는 file들 중에 최종적으로 남길 file들을 스냅샷하는 과정을 commit한다고 한다. 이는 git directory에 영구적인 스냅샷으로 담겨진다. 

- 사용방법 

  ~~~ bash
  $ git commit -m 'first commit'
  ~~~

  ''안의 message 정하는 방법은 하나씩 해보자. 

  

  ### git status

- 개념 : 이는 git 작업의 단계를 수행할 때 마다 명령이 잘 반영 되었는지 상태를 확인해주기 위함이다. 수시로 확인하고 문제가 발생했을 때 또한 이를 이용한다. 

- 사용방법

  ~~~ bash
  $ git status
  ~~~

  명령을 실행하고 뜨는 메시지를 확인해서 file의 상태, add작업 수행의 확인, commit 상태를 확인할 수 있다. 

  1. 파일을 수정하고 저장한 뒤 add하지 않은 상태이면 Modified상태이다. 
  2. 파일을 add했다면 Staged 상태이다. 
  3. 그리고 commit하여 git-directory에 위치한 파일들의 상태는 Committed 상태이다. 

  ### git log

- 개념: commit과정이 끝난뒤 그 리스트를 확인할 수 있다. 

- 사용방법

  ~~~ bash
  $ git log
  $ git log --oneline #파일명을 간단하게 볼 수 있다
  ~~~

  - commit할때 m- ''에 쓴 이름들을 확인하여 점검한다. 
