#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> correct_tmp;
    // 학생 123의 찍기 순서
    int std1[5] = {1,2,3,4,5};
    int std2[8] = {2,1,2,3,2,4,2,5};
    int std3[10]= {3,3,1,1,2,2,4,4,5,5};
    // 맞춘갯수 담는 변수
    int correct[3] = {0};
    
    // 누가 많이 맞췄는지 카운팅
    for(int i=0;i <answers.size();i++){
        if (answers[i] == std1[i%5]){
            correct[0]++;
        }
        if (answers[i] == std2[i%8]){
            correct[1]++;
        }
        if (answers[i] == std3[i%10]){
            correct[2]++;
        }
    }

    // 맞춘 갯수 복사 후 소팅
    for (int i=0;i<3;i++){
       correct_tmp.push_back(correct[i]);
    }
    sort(correct_tmp.begin(), correct_tmp.end());

    // 제일 많이 맞춘 학생 찾기 (중복가능)
    bool is_pushed[3]={false}; // 중복 배제를 위한 변수
    int tmpScore = correct_tmp[2]; // 최댓값 찾기 위한 변수
    
    for(int i=2; i>=0; i--){
        if(tmpScore > correct_tmp[i]){
            break;
        }
        if(correct_tmp[i] == correct[0] && !is_pushed[0]){
           answer.push_back(1);
            is_pushed[0] = true;
       }
        if(correct_tmp[i] == correct[1]&& !is_pushed[1]){
           answer.push_back(2);
            is_pushed[1] = true;
       }
        if(correct_tmp[i] == correct[2] && !is_pushed[2]){
           answer.push_back(3);
            is_pushed[2] = true;
       }
    }
    
    // 정답
    return answer;
}