#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
int gTarget = 0;
int gAnswer = 0;

void NextCalculate(int num, int idx, vector<int> &numbers){
    
    if (idx == numbers.size()){
        if (num == gTarget){
            gAnswer++;
        }
        return ;
    }
    
    NextCalculate(num-numbers[idx], idx+1, numbers);
    NextCalculate(num+numbers[idx], idx+1, numbers);
    
}


int solution(vector<int> numbers, int target) {
    gAnswer = 0;
    gTarget = target;
    NextCalculate(0, 0, numbers);
    
    return gAnswer;
}