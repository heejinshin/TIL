//함수레벨에서 let과 var차이 확인하기
console.log(x) //undefined, 선언은 됐는데 값이 없는상태를 말함
for(let x = 8; x < 10; x++){  //let은 block scope를 가져서 for문안에서만 쓸 수 있다
    console.log('x의 값은' + x);
}
console.log(`x의값은 ${x}`)  //is not defined에러 , 선언되지 않았다.
