#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;
    int i = 1, sum = truck_weights[0];
    queue<int> passing;

    passing.push(truck_weights[0]);
    
    while(1){
        
        // 마지막 트럭 다리에 진입
        if (i == truck_weights.size()){
            time += bridge_length;
            break;
        }
        
        // 다리를 다 지났을 때
        if (passing.size() == bridge_length){
            int popTruck = passing.front();
            sum = sum - popTruck;
            passing.pop();
        }
        
        
        // 다리 진입 여부 체크
        sum = sum + truck_weights[i];
        
        if(sum <= weight){
            passing.push(truck_weights[i++]);
        } else{
            sum = sum - truck_weights[i];
            passing.push(0);
        }

        // 시간 업데이트
        time++; 
    }

    return time;
}