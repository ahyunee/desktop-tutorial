#include <string>
#include <vector>
#include <iostream>
#include <algorithm>  // std::find

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    
    vector<string>::iterator it = find(seoul.begin(), seoul.end(), "Kim");

    int idx = it - seoul.begin();
    answer = "김서방은 " + to_string(idx)+"에 있다";
    return answer;
}