#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    
    for(int i=0; i<skill_trees.size(); i++)
    {
        int pt = -1; // 선행스킬트리 포인터
        for(int j=0;j<skill_trees[i].length(); j++){
            for (int k=0;k <skill.length();k++){
                // 스킬트리 문자열 중, 선행스킬트리 만났을 때
                if (skill[k] == skill_trees[i][j]){ 
                    pt++;
                    // 선행스킬트리 차례랑 스킬트리 문자열 중 선행스킬트리랑 문자열 차례랑 같아야 함.
                    if(pt!=k){
                        j= skill_trees[i].length();
                        answer --;
                    }
                }
            }
        }
    }
    
    return answer;
}