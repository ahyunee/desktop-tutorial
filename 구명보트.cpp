#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    int j = people.size()-1;
    sort(people.begin(), people.end(), greater<int>());
    
    for (int i=0; i< people.size();i++){
        if(people[i]+people[j] <= limit){
            answer++; // 같이 탐
            j--;
        }else{
            answer++; // 혼자탐
        }
        if (i>=j)
        {
            break;
        }
    }

    return answer;
}