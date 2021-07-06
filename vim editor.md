# vim editor

vim은 코드를 터미널창에서 간편하게 수정하기 위해 사용하는 편집기이다.

- 사용 방법

  1. vim [a.py](http://a.py)
  2. i 누르면 insert모드(편집가능상태)
  3. 편집(코드입력)
  4. 편집 종료 후 [esc]를 눌러서 커맨드 모드(편집이 끝나고 명령할 수 있는 상태)
  5. 커맨드 모드에서 [:w] + enter ⇒ 저장
  6. 커맨드 모드에서 [:q] + enter ⇒ 종료
  7. [:wq] + enter ⇒저장 종료
  8. [:qw] + enter ⇒강제 종료
     - dd ⇒ 라인 delete

  - commit메시지 수정할 때

    - git add후에 (.으로 올리면 LF CRLF경고가 뜨는데 이건 무시해도 된다) commit을 -m없이 쓰면 message를 입력하라는 말이 뜬다. 또는

    ```python
    $ git commit --amend
    ```

    그치만 사실 두단계 이상 전단계 꺼는 수정하지 않는다. commit고유번호(노란코드)가 바뀌기 때문에..!

