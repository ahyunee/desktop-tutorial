#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    
    for(int i=0;i<501;i++)
    {   
        // 종료조건(n=1)이거나 500회 넘었을 때 -> 처음에 1이 들어 올 수 있으므로 먼저 비교 수행
        if(n==1 || i==500) 
        {
            answer = i;
            break;
        }

        (n&1)?(n=n*3+1):(n=n/2);
    }
    
    if(answer >= 500) // 500을 지나도 만족 못하는 경우 -1 리턴
    {
        answer = -1;
    }
    
    return answer;
}