#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    sort(scoville.begin(), scoville.end());
    deque <int> scov;
    for(int i:scoville){
        scov.push_back(i);
    }
   
    while(scov.size() >= 2 && scov.front()<K){
        int n1 = scov.front();
        scov.pop_front();
        int n2 = scov.front();
        scov.pop_front();
        int nFood = n1 + n2*2;

        bool isPushed = false;
        for(int i=0; i<scov.size();i++){
            if(scov[i] > nFood)
            {
                deque<int>::iterator iter = scov.begin() + i;
                scov.insert(iter, nFood);
                isPushed = true;
                break;
            }
        }
        
        if(!isPushed){
            scov.push_back(nFood);
        }

        answer++; 
    }

    if (scov.front() < K){
        answer = -1;
    }
    return answer;
}