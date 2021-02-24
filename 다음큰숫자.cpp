#include <string>
#include <vector>

using namespace std;

int traslateAndCountNum1(int n){
    int cnt = 0;
    
    while(n > 1){
        if (n%2 == 1){
            cnt++;
        } 
        n=n/2;
    }
    
    return cnt;
}


int solution(int n) {
    int answer = 0;
    int nOne = traslateAndCountNum1(n);
    n++;
    
    while(1){
        if(traslateAndCountNum1(n)==nOne){
            answer = n;
            break;
        }
        n++;
    }
    
    return answer;
}