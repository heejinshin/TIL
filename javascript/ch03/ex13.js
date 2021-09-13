// 필수 인수
function show(x, y = 1){  //x는 지정을 안해준것
    console.log('x=' + x)
    console.log('y=' + y)
}

show()

function required(){  // 호출하면, 예외를 발생시키는 역할, 예외발생용으로 만든 함수 
    throw new Error('인수가 부족합니다')
}

function hoge(value = required()){  // 인자 default값 설정 표현한 식, required의 리턴값으로서 초기값을 주겠다 
    // but 아래서 예외를 던지기 때문에 리턴값 x 따라서 예외가 발생하고 중단됨
    return value
}

// hoge()
// hoge(10)  //예외발생문(required) 호출 안되고 value 10으로 정상처리
console.log(hoge(10))