#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string tmp;
    vector <int> num;
    
    for(int i=0;i<s.size(); i++){
        if(s[i]==' '){
            num.push_back(atoi(tmp.c_str()));
            tmp="";
        }else {
            tmp+=s[i];
        }
        
    }
    num.push_back(atoi(tmp.c_str()));
    sort(num.begin(), num.end(), greater<int>());
    answer = to_string(num.back())+" "+ to_string(num.front());
    return answer;
}
