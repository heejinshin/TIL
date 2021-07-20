#  SQL(2)

- 내부조인



## 내부조인

조인이라하면 보통 내부조인을 말한다. 조인이란 두 개 이상의 테이블을 하나로 구성하는 것을 말한다. 

~~~ sql
SELECT <열 목록>
FROM <첫 번째 테이블>
			INNER JOIN <두 번째 테이블>    #Inner 안써도 내부조인으로 인식됨
			ON <조인될 조건>
[WHERE 검색조건]
~~~

내부조인을 사용하기 위한 경우를 보자. 구매테이블에는 물건을 구매한 사용자의 아이디와 물건의 정보만 나타난다. 그런데 물건을 배송하기 위해서는 회원의 주소를 알아야하고 이는 회원테이블에 담겨져있는 정보이다. 주소 정보를 알기위해 회원테이블과 구매테이블을 결합하는 조인이 내부조인이다. 

~~~ SQL
USE sqldbb
SELECT *
		FROM buyTBL
			INNER JOIN userTBL
					ON buyTBL.userID = userTBL.userID
		WHERE buyTBL.userID = 'JYP';
-- 우선 buyTBL에서 'JYP'라는userID를 찾는다.
-- 'JYP'를 userTBL에서도 찾아 있으면 두 행을 결합한다.
-- WHERE구문을 안써주게되면 모든행에 대해 동일한 작업을 반복하게 된다. 
~~~

*자주 발생하는 오류 이유_ 작성할 db파일이 active되어있는지 상시 확인해주고 써야한다.

ON구문과 WHERE구문의 조건이 '테이블이름.열이름'의 형태로 되어있다. 이는 각 테이블의 동일한 이름의 열이 존재하기 때문에 어느테이블의 열인지 구분해주기 위함이다. 두 개의 테이블을 결합하는 경우 동일한 이름이 있다면 반드시 '테이블명.열이름'형태로 표기해주어야 한다. 
