#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    map<int, int, greater<int>> ct;     // 0:인용 횟수, 1:해당 인용횟수인 논문 수

    for (int i : citations)
    {
        if (ct.count(i) == 0)
        {
            ct.insert(make_pair(i, 1));
        }
        else
        {
            ct[i]++;
        }
    }

    int nn_cnt =  ct.begin()->second;

    for (auto it = ct.begin(); it != ct.end(); it++)
    {   
        //cout<<"\n"<<it->first<<","<<it->second;
        if (it->first < nn_cnt) {
            it--;
            answer = nn_cnt- (it->second);
            return answer;
        }
        answer = nn_cnt; 
        nn_cnt+=it->second;
    }

    return answer;
}