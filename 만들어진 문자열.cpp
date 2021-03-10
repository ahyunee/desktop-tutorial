#include <iostream>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    
    if (s.length()%2 == 1 ){
        return 0;
    }
    
    for (int i=1; i<s.length(); i++){
        
        if(s[i] == s[i-1]){
            string s1 = s.substr(0, i-1);
            string s2="";
            if (i+1 < s.length()){
                 s2 = s.substr(i+1, s.length());
            }
            i = 0;
            s = s1+s2;
            //cout <<"만들어진 문자열:"<<s<<"\n";
        }
        
    }
    
    if (s==""){
        answer = 1;
    }

    return answer;
}