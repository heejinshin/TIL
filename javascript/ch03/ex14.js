// 가변길이 인수 - 나머지 인수(나머지 연산자 배열)
function sum(...nums){  //배열생성
    let result = 0
    for(let num of nums){
        if(typeof num !== 'number'){
            throw new Error('지정값이 숫자가 아닙니다:'+num)
        }
        result += num
    }
    return result
}

try {
    console.log(sum(1, 2, 3, 4, 5))
    console.log(sum(1, 2, 3, 4, true))
} catch(e) {
    console.log(e.message)
}