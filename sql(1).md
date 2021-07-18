# SQL(1)

- 대소문자는 입력무관하게 시스템에서 자동변경 됩니다.



## 기본지식

- primary key, -제약조건

  - 각 행의 데이터를 고유하게 구분하는 최소의 정보

  - not null과 unique제약 조건, 이 제약조건이 설정된 필드는 null값을 가질 수 없으며 중복값을 가져서도 안된다. (반드시 not null로 설정)

  - 테이블의 데이터를 빠르게 찾을 수 있도록 돕는다. (성능)

  - rdb(관계형db)이론상 모든 테이블은 반드시 하나 이상의 기본키를 가져야 한다고 한다. 

  - 관례상 첫번째 컬럼으로 배치한다

    

## MariaDB 데이터형식

- 숫자데이터 형식: INT, SMALLINT, FLOAT, DECIMAL...

- 문자데이터 형식: CHAR, VARCHAR, TEXT...

- 날짜형식: DATE, DATETIME, TIME...

- 기타: JSON

  hiedi에서 데이터테이블 열 추가 할때 선택해서 넣을 수 있었다. 

  

## 기본, 구축

~~~ sql
-- 구축할 때 명령어
> mysql -u root -p  -- mysql 실행파일 경로를 path에 환경변수로 먼저 등록한다.
> SOURCE 파일명
-- 기본 명령어
> USE 데이터베이스명; -- 사용할 데이터베이스명
> DESC 테이블명; -- 테이블의 구조 출력
> CREATE database sqldb; -- 데이터베이스 생성

~~~

명령 끝에는 ;을 써야 다음 명령으로 넘어갈 수 있다



## SELECT문

~~~ sql
SELECT 필드 목록
FROM 테이블명
WHERE 조건
GROUP BY 컬럼명
HAVING 조건
ORDER BY 컬럼명
~~~

- where절 

  - And, or, not

  ~~~ sql
  SELECT userid, name
  FROM usertbl
  WHERE birthyear >= 1970 AND height >= 180;
  
  SELECT userid, name
  FROM usertbl
  WHERE birthyear >= 1970 OR height >= 180;
  ~~~

  - BETWEEN ~ AND

    ~~~ sql
    -- 키가 180에서 183사이인 사람 찾기
    SELECT Name, height FROM usertbl WHERE height BETWEEN 180 AND 183;
    -- 숫자로 구성되어 있고 연속적인 값을 가지고 있어서 between ~and를 쓸 수 있다. 	
    ~~~

  - IN()

    ~~~ sql
    -- 연속적인 값이 아닌 특정값 찾을 때 사용
    SELECT Name, addr FROM usertbl WHERE addr IN('경남, 전북, 충남')
    ~~~

  - LIKE

    ~~~ sql 
    -- 문자열의 내용을 검색
    SELECT Name, height
    FROM usertbl
    WHERE Name LIKE '김%';
    -- %는 글자수에 상관없이 해당 글자가 들어간 것을 찾는다
    ~~~

    

- SubQuery(하위커리), 중요..!!

  - From/where절에 select문을 제시
  - 반드시 ()안에 작성

  ~~~ sql
  SELECT name, height FROM usertbl WHERE height > 180;
  -- 키가 180보다 큰 사람 출력
  SELECT name, height FROM usertbl
  		WHERE height > (SELECT height FROM usertbl WHERE name = '김경호')
  -- 키가 김경호보다 큰 사람 출력
  ~~~

- ORDER BY

  - 결과의 순서를 조정

  ~~~ sql
  SELECT name, mdate FROM usertbl ORDER BY mdate;   
  -- mdate의 오름차순으로 정렬, ASC가 default값이라 생략
  SELECT name, mdate FROM usertbl ORDER BY mdate DESC;
  -- mdate의 내림차순으로 정렬, DESC
  ~~~

  

- 중복된 것은 하나만 남기는, 파이썬에서의 집합과 같은 기능, DISTINCT

  ~~~ SQL
  SELECT DISTINCT addr FROM usertbl;
  ~~~

  

- 가장 어려웠던.. 출력하는 개수를 제한하는 LIMIT

  - select문에서는 자료개수에 상관없이 모든 자료가 요청된다. 자료가 많은 경우 원하는 범위를 보기가 어렵다. 

  - LIMIT(시작위치, 반환할 개수)

  ~~~ SQL
  USE employees(파일명);
  
  SELECT hire_date FROM employees 
  ORDER BY hire_date ASC
  LIMIT 0, 5 --Limit 5 offset0(0부터)
  ~~~

  ​	실습을 하면서 직관적으로 보기좋도록 예약어별로 줄바꿈을 했다.
  

- GROUP BY

  그룹으로 묶어준다

  ~~~ sql
  SELECT userid, SUM(amount)
  FROM buytbl
  GROUP BY userid;
  -- userid별로 sum값만을 보겠다
  ~~~



- 집계함수

  - 데이터를 그룹화해주는 기능

  ~~~ sql 
  SELECT COUNT(*) FROM usertbl -- 전체 행의 개수
  ~~~

  - GROUP BY와 함께 자주 사용되는 집계함수

