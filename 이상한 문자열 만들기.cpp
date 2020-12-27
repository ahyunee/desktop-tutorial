#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

string solution(string s) {
    string answer = "";
    bool isOdd = false;
    
    for (int i=0;i<s.length();i++){
        if(s[i]==' '){
            answer+=" ";
            isOdd = false; //홀짝 초기화
            continue;
        }
        int n = s[i];
        
        if(isOdd) // 홀수번째 문자열: 소문자
        {
            if(n < 'a')
                n +=32;
        }
        else    // 짝수번째 문자열: 대문자
        {
            if(n >= 'a')
                n -=32;
        }
        printf("%c", n);
        isOdd = !isOdd;
        char c = n;
        answer+=c;
    }
    return answer;
}