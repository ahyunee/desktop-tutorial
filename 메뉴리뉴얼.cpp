#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;


vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    int maxCourse[11] = {-1};
    map <string, int> nCurse;
    
    // orders[i] 값들 정렬
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(), orders[i].end());
        
        for (int j=0; j<course.size(); j++){
            vector <int> tmpVector;
            int nam = orders[i].length() - course[j];
            if(nam < 0)
                continue;

            for (int k=0; k<course[j]; k++){
                tmpVector.push_back(1);
            }
            for(int k=0; k<nam; k++){
                tmpVector.push_back(0);
            }

            sort(tmpVector.begin(), tmpVector.end());
            int max = 0; // i번째 사람이 주문한 요리를 j개로 쪼갰을 때의 최댓값
            // 순열 구하기
            do{
                string strChapped = "";
                for(int k=0; k<tmpVector.size(); k++){
                    if (tmpVector[k])
                        strChapped+=orders[i][k];
                }
                if (nCurse.count(strChapped) == 0 ){
                    nCurse.insert(make_pair(strChapped, 1));
                }
                else {
                    nCurse[strChapped]++;
                    max < nCurse[strChapped] ? max= nCurse[strChapped] : max=max;
                }
            }while(next_permutation(tmpVector.begin(), tmpVector.end()));

            maxCourse[course[j]] < max ?  maxCourse[course[j]]=max : maxCourse[course[j]];
        }
    }

    for (auto it=nCurse.begin(); it !=nCurse.end(); it++){
        int idx = it->first.length();
        if(it->second >= 2 && it->second == maxCourse[idx]){
            answer.push_back(it->first);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}