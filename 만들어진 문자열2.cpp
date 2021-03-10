#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack <char> stk;
    
    if (s.length() %2 != 0){ // 홀수
        return 0;
    }
    
    for(int i=0; i<s.length(); i++){
        if(stk.empty()){
            stk.push(s[i]);
        }
        else {
            char nc = stk.top();
            if (nc == s[i]){
                stk.pop();
            }else{
                stk.push(s[i]);
                
            }
        }
    }
    
    while(!stk.empty()){
        
        int n = stk.top();
        stk.pop();
        if (n==stk.top()){
            stk.pop();
        }
        else{
            return 0;
        }
    }
    
    if (stk.empty())
        return 1;
    else 
        return 0;
}