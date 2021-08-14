# 가상환경 설치 

아나콘다로 가상환경 만들기

conda create -n webapp1 python-3.8 -> 가상환경 설치

conda env list -> 가상환경 만들어진것 확인

conda activate webapp1-> 가상환경 활성화 

(webapp1) 활성화된 가상환경으로 경로가 뜬다



이 상태에서 pip install Django, 장고를 설치해준다

유의할 점은 cwd가 만들어둔 django폴더여야 한다 

프로젝트를 생성한다

django-admin startproject mysite-> 프로젝트 기본골격을 만들어주는 작업

프로젝트명을 mysite로 (config라고 운영하기도 한다) 해서 바깥쪽 폴더명만 web_app1으로 바꿔주었다 (->프로잭트 디렉토리는 web_app1위치)

(안쪽 mysite에는 설정 파일이 배치가 된다

설정파일중 init은 이 디렉토리가 패키지임을 나타내는 내용없는 파일이다 )

코드를 실행할때 web_app1에서 작업한다 

f1키를 눌러 conda경로를 web_app1로 바꿔주고 터미널을 열어준다

 python manage.py runserver ->장고서버를 기동시키는 작업

이를 최초실행 시 default로 사용하는 db파일이 하나 생긴다 

Co
