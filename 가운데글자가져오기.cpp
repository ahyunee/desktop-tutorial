#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int pos = s.length()/2;
    
    if (s.length()%2 ==0 ){ // 짝수: 배열은 0부터 시작하므로 인덱스 -1
        answer = s.substr(pos-1, 2);
    }
    else // 홀수 : 2로 나누면 한자리 내려기므로 인덱스 그대로 쓰기
    {
        answer = s[pos];
    }
    
    return answer;
}