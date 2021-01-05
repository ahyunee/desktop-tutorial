#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=0;i<prices.size();i++){
        bool isPushed = false;
        // cnt 가격떨어지지 않은 횟수
        for(int j=i+1, cnt=1; j<prices.size(); j++, cnt++){
            if(prices[i]>prices[j]){
                answer.push_back(cnt);
                isPushed = true;
                break;
            }
        }
        if(!isPushed){
            answer.push_back(prices.size()-i-1);
        }
        
    }
    
    return answer;
}