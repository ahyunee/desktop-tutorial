#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(string a, string b){
    
    int n1 = stoi(a+b);
    int n2 = stoi(b+a);

    return n1>n2;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;

    for(int i=0; i<numbers.size(); i++){
        tmp.push_back(to_string(numbers[i]));
    }
    sort(tmp.begin(), tmp.end(), compare);

    for(int i=tmp.size()-1; i>=0 ;i--){
        cout<<tmp[i];
    }

    return answer;
}