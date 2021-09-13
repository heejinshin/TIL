function weightSum(weight, ...nums){
    let result = 0
    for(let num of nums){
        if(typeof num !== 'number'){
            throw new Error('지정값이 숫자가 아닙니다:' + num)
        }
        result += num * weight
    }
    return result
}

try {
    console.log(weightSum(0, 1, 2))
} catch(e) {
    console.log(e.message)
}