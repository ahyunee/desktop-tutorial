#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map <string, int> spy;

    for(int i=0;i<clothes.size();i++){
        if (spy.count(clothes[i][1]) == 0){
             spy.insert(make_pair(clothes[i][1],1)) ;
        }else { 
            spy[clothes[i][1]]++;
        }
    }


    for (auto it = spy.begin(); it != spy.end(); it++) {
        // 안입는 경우의 수 더해서 계산
		answer*=((it->second)+1);
	}

    answer = answer-1;

    return answer;
}