# polls앱 만들기

코드 터미널창에서 작업

> python manage.py startapp polls 

웹사이트가 제공하는 기능그룹 하나를 app이라고 부른다 

파이썬 입장에서는 polls라는 패키지가 하나 생기는것 (mysite랑 같은위치)

* mysite setting.py에서 installed_apps목록(장고에서 기본적으로 제공하는 app목록)에 'polls'(문자열로등록유의)를 추가한다

~~~ python
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.sqlite3',
        'NAME': BASE_DIR / 'db.sqlite3',
    }
}
#default로 sqlite3로 진행되는것을 알 수 있다
~~~

~~~ python
#이부분 변경
LANGUAGE_CODE = 'ko-kr'

TIME_ZONE = 'Asia/Seoul'

 #데이터베이스에 시간을 저장할때 타임존정보도 같이 저장할건지 여부
USE_I18N = True    

USE_L10N = True

USE_TZ = False
~~~

- sql connecct 연결(db.sqlite3파일), 세션생성

> python manage.py migrate -> 세션에 default 테이블 만들어주는 작업

