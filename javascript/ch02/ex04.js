var i = 1;
try{
    i = i * j
}catch(e){  //e는 에러 정보 객체
    console.log(e.message)  //message에 에러 이유를 담는다
}finally{
    console.log('처리가 완료되었다.')
}