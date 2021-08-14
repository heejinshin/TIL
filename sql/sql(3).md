# sql(3)- 테이블

## 테이블 제약조건

- 제약조건 
  *데이터의 무결성을 위함이다. 데이터 무결성이란 데이터베이스의 요소가 훼손되지않고 정확하고 안전하게 유지되는 것을 말한다.

  | 제약조건             | 설명                                                         |
  | -------------------- | ------------------------------------------------------------ |
  | PRIMARY KEY 제약조건 | 테이블에 존재하는 많은행의 데이터를 구분하기 위한 제약조건 / 중복, NULL 비허용 |
  | FOREIGN KEY 제약조건 | 테이블간의 관계를 선언 / 하나의 테이블이 다른 테이블에 의존하는 형태 |
  | UNIQUE 제약조건      | 중복되지 않는 유일한 값을 입력해야 하는 조건                 |
  | CHECK 제약조건       | 입력되는 데이터를 점검하는 기능                              |
  | DEFAULT 정의         | 값을 입력하지 않았을 때 자동으로 입력되는 기본값을 정의      |
  | NULL값 허용          | 빈 값을 허용 / 데이터 생략 가능                              |

- PRIMARY KEY 제약조건 ( 기본 키 제약조건)
  - 테이블에 지정된 키 보는법 

  ~~~ sql
  	SHOW KEYS FROM 테이블이름;
  ~~~
  - 이미 만들어진 테이블을 ALTER구문을 사용하여 PRIMARY KEY 설정하기

  ~~~ sql
  ALTER TABLE 테이블명
  	ADD CONSTRAINT PK_테이블명_컬럼명    -- 제약조건 추가, comstraint뒤에 제약조건의 명칭을 써준다*[타입_테이블명_컬럼명]
  		PRIMARY KEY(컬럼명);     				-- 기본키 제약조건 설정
  ~~~

  - 복합키(두 개 이상의 컬름으로 키를 구성)

  ~~~ sql
  PRIMARY KEY(컬럼명1, 컬럼명2);
  ~~~

  - PRIMARY KEY를 지정하면 INDEX객체가 자동 생성된다. 그것을 정렬해서 관리하고 결과적으로 검색속도를 향상시킨다. 
  - 테이블 정보 확인

  ~~~ sql
  SHOW INDEX FROM 테이블명    -- 기본키 설정상태를 확인할 수 있다
  ~~~



- FOREIGN KEY 제약조건 ( 외래 키 제약조건)

  - 외래키에의해 참조가 되는 테이블을 기준테이블로 본다. 
  - 외래 테이블에 데이터를 입력할 때는 기준테이블이 참조되므로 기준테이블에 데이터가 존재해야하며 기준테이블의 열은 반드시 PRIMARY KEY이거나 Unique 제약조건이 설정되어 있어야 한다. 

  - 조건 거는 방법

    ~~~ sql
    CREATE TABLE 테이블명(
    	~
    	FOREIGN KEY(컬럼명) REFERENCES 기준테이블명(컬럼명)       -- 외래키 테이블의 열에 기준테이블의 열을 참조시킨다
    )																											-- 기준테이블의 열과 외래키 테이블의 열 이름은 달라도 무관
    ~~~

  - ALTER구문 이용하기

    ~~~ sql
    ALTER TABLE 테이블명 																	-- 테이블을 수정한다
    	ADD CONSTRAINT FK_기준테이블명_외래테이블명       			-- 제약조건을 정한다
    	FOREIGN KEY (컬럼명)																-- 외래키 제약조건을 외래테이블 컬럼명에의해 설정한다
    	REFERENCES 기준테이블명(컬럼명)											 -- 참조할 기준테이블을 적어준다
    ~~~

  - 테이블 정보 확인

    ~~~ sql
    SHOW INDEX FROM 외래테이블명
    ~~~

  -  CASCADING: 사전적 정의는 폭포수, 이는 기준테이블의 데이터가 변경되었을 때 외래 키 테이블도 자동으로 적용되도록 설정한다

    ~~~ SQL
    REFERENCES ~다음으로 작성
    ON UPDATE CASCADE;
    ~~~

  

- UNIQUE 제약조건

  - primary키와 비슷하며 차이점은 NULL값을 허용한다 

  - NULL은 여러개가 입력되어도 상관없다

  - 회원테이블의 예로 주로 email을 unique로 설정한다 

    ~~~ sql
    CREATE TABLE usertbl
    (
    	컬럼생성...
    	~
    	CONSTRAINT AK_email UNIQUE(email)     -- 제약조건 설정시 unique는 AK를 주로 사용한다(Alternate Key)
    );
    ~~~



- CHECK 제약조건

  - 입력되는 데이터를 점검하는 기능

  - key에 마이너스 값을 안받게 한다던지, 출생년도, 키 등의 정보에 조건을 지정한다던지

    ~~~ sql
    CREATE TABLE usertbl
    (
    	birthYear INT CHECK (birthYear >= 1900 AND birthYear <= 2020),   -- birthYear라는 열 지정, CHECK 조건지정
    	CONSTRAINT CK_name CHECK(name IS NOT NULL)		-- 위에서 name열을 지정 후 조건을 추가한 방식
    );
    ~~~

  - 마찬가지로 필요하다면 열을 정의한 후에 ALTER TABLE문으로 제약조건을 추가할 수 있다.

  - CHECK에서 사용할 수 있는 조건은 SELECT문의 WHERE구문에 오는 조건과 거의 비슷한 형태의 것들로 쓴다 

    

- DEFAULT 정의

  ~~~ SQL
  CREATE TABLE ~ (mDate date NULL DEFAULT SYSDATE());   --default값으로 현재 날짜를 설명한다
  ~~~

  - ALTER문 사용

    ~~~ sql
    ALTER TABLE 테이블명
    		ALTER COLUMN height SET DEFAULT 170; 							-- 열에 default를 지정하기 위해 ALTER COLUMN문을 사용한다 
    ~~~

- NULL 값 허용
  - NULL값을 허용하려면 NULL을, 허용하지 않으려면 NOT NULL을 사용한다 
  - Primary key가 설정된 열에는 자동으로 not null로 인식된다(데이터값 필수)
  - NULL값은 '아무것도 없다'라는 의미로 공백(' ')이나 0과는 다른값이라는 것에 주의하자



## 테이블 삭제

 ~~~ 
 DROP TABLE 테이블이름;
 ~~~

- 외래키 제약조건의 기준테이블이 되는 테이블은 삭제할 수 없다. 먼저 외래 키 테이블을 삭제한 후 참조테이블을 삭제해야 한다. 

  

