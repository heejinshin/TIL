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
> source 파일명
-- 기본 명령어
> use 데이터베이스명; -- 사용할 데이터베이스명
> DESC 테이블명; -- 테이블의 구조 출력
> create database sqldb; -- 데이터베이스 생성

~~~

명령 끝에는 ;을 써야 다음 명령으로 넘어갈 수 있다



## SELECT문

~~~ sql
SELECT 필드 목록
FROM 테이블명
[where 조건]
[group by 컬럼명]
[having 조건]
[orderby 컬럼명]
~~~

- where절 

  - And, or, not

  ~~~ sql
  select userid, name
  from usertbl
  where birthyear >= 1970 and height >= 180;
  
  select userid, name
  from usertbl
  where birthyear >= 1970 or height >= 180;
  ~~~

  - between, in(), like
    - like는 자주쓰인다

  ~~~ sql
  select name, height
  from usertbl
  where name like '김%';
  -- %는 글자수에 상관없이 해당 글자가 들어간 것을 찾는다.
  ~~~

  

- SubQuery(하위커리), 중요..!!

  - From/where절에 select문을 제시
  - 반드시 ()안에 작성

  ~~~ sql
  select name, height from usertbl where height > 180;
  -- 키가 180보다 큰 사람 출력
  select name, height from usertbl
  		where height > (select height from usertbl where name = '김경호')
  -- 키가 김경호보다 큰 사람 출력
  ~~~

- ASC, DESC - 정렬

  ~~~ sql
  select name, mdate from usertbl order by mdate;
  -- mdate의 오름차순으로 정렬
  select name, mdate from usertbl order by mdate desc;
  -- mdate의 내림차순으로 정렬
  ~~~

  

- 중복을 없애는..! 파이썬에서의 집합과 같은 기능, DISTINCT

  ~~~ SQL
  SELECT DISTINCT addr from usertbl;
  ~~~

  

- 가장 어려웠던.. 출력하는 개수를 제한하는 LIMIT

  select문에서는 자료개수에 상관없이 모든 자료가 요청된다. 자료가 많은 경우 원하는 범위를 보기가 어렵다. 

  LIMIT(시작위치, 반환할 개수)

  ~~~ 
  USE employees(파일명);
  
  select hire_date from employees 
  	order by hire_date ASC
  	LIMIT 0, 5 --Limit 5 offset0(0부터)
  ~~~

  

- GROUP BY

  LIMIT와 마찬가지로 특정 범위만을 살펴보기 위해 쓰면 된다. 

  특정 컬럼에 대해 동일한 값을 가지는 행들을 하나의 행으로 처리, 통계작업

  ~~~ sql
  select userid, sum(amount)
  from buytbl
  group by userid;
  -- userid별로 sum값만을 본다, 변수명 뒤에 as를 붙이면 원하는 이름으로 열name을 지정한다.
  ~~~



- 집계함수

  ~~~ sql 
  select count(*) from usertbl -- 전체 행의 개수
  ~~~

  

