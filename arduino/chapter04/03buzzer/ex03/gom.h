#include <pitches.h>   //넓은 옥타브에 걸친 음계 라이브러리 파일, 아두이노의 example파일에 있는 항목인데 내 폴더엔 없었고 강사님꺼로 대체

int notes[] = { 
NOTE_C4, NOTE_C4, NOTE_C4,NOTE_C4,NOTE_C4,       // 도도도도도
NOTE_E4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4,        //미솔솔미도
NOTE_G4, NOTE_G4, NOTE_E4,  //솔솔미
NOTE_G4, NOTE_G4, NOTE_E4,  //솔솔미
NOTE_C4, NOTE_C4, NOTE_C4,  //도도도

NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4, //솔솔미도  
NOTE_G4, NOTE_G4, NOTE_G4,      //솔솔솔
NOTE_G4, NOTE_G4, NOTE_E4,NOTE_C4,      //솔솔미도
NOTE_G4, NOTE_G4, NOTE_G4,      //솔솔솔

NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4, // 솔솔미도 
NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, // 솔솔솔라솔 
NOTE_C5, NOTE_G4, NOTE_C5, NOTE_G4, // 도솔도솔 
NOTE_E4, NOTE_D4, NOTE_C4}; // 미레도


int durations[] = {    4,8,8,4,4, 4,8,8,4,4, 8,8,4,8,8,4,4,4,2, 4,4,4,4, 4,4,2,4,4,4,4, 4,4,2,
4,4,4,4, 8,8,8,8,2, 4,4,4,4,4,4,2};
// 연주 길이 정의 4:4분 음표,8:8분 음표 };