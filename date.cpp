#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string dayName[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int mDay[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int nDay = 0; // a월 b일을 n일자로 저장할 변수
    
    // 월 계산 (5월이면 4월까지 더해야 함 --> 5월은 날짜가 덜 채워졌으므로)
    for (int i=0; i<a-1; i++){
        nDay += mDay[i]; 
    }
    // 일자 계산
    nDay += b;
    
    // 요일 위치 조정 (7로 나눴을 때 배열 인덱스가 화요일이 1이 되게)
    nDay += 3;
    answer = dayName[nDay%7];
    
    return answer;
}