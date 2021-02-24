#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1; // 자기 자신
    // 연속된 숫자이기 때문에 범위 :n/2+2
    for (int i=1;i< n/2+2; i++){
        int sum = 0;
        
        for(int j=i; j<n/2+2; j++){
            sum += j;
            
            if (sum == n){
                answer++;
                break;
            }else if(sum > n){
                break;
            }
        }
    }
    
    
    return answer;
}