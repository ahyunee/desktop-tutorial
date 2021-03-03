#include <string>
#include <vector>
#include <iostream>
using namespace std;

string makeBinaryNum(int num){
    string tnum = "";
    string bnum = "";
    
    while(1){
        tnum += to_string(num%2);
        num = num/2;
        
        if(num == 0){
            break;
        }
    }
    
    for(int i=tnum.length() -1 ; i>=0; i--){
        bnum += tnum[i];
    }
    return bnum;
}

vector<int> solution(string s) {
    vector<int> answer;
    int nChangedCnt    = 0;
    int nRemovedZeroCnt = 0;
    
    if (s=="1"){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    
    
    while(1){
        nChangedCnt++;
        int num1 = 0;
        
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1'){
                num1++;
            }
        }
        
        nRemovedZeroCnt = nRemovedZeroCnt + s.length() - num1;
        s = makeBinaryNum(num1);
        
        // 종료조건
        if(s=="1"){
            answer.push_back(nChangedCnt);
            answer.push_back(nRemovedZeroCnt);
            return answer;
        }
    }
}