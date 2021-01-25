#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    long long tmpNum = n;
    
    while(1){
        
        long long mock = tmpNum/3;
        long long rem  = tmpNum%3;
        
        if(rem == 0){
            answer ='4'+answer;
            mock --;
        }else if(rem == 1){
            answer ='1'+answer;
        }else if(rem == 2){
            answer = '2'+answer;
        }
        
        if (mock==0)
        {
            break;
        }
    }
    
    return answer;
}

int main(void){
    cout<<solution(513);
    return 0;
}