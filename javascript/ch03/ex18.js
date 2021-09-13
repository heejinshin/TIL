// 객체정의{}
// 함수에 키워드로 인수전달

function show({name}){
    console.log(name)
}

let member = {
    mid: 'Y0001',
    name: '정시온',
    address: 'shion_jung@example.com'
}

show(member)