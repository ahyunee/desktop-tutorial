#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    bool bIncorrect = false;
    char lastWord = words[0][words[0].length()-1];
    unordered_map<string, bool> word;
    word.insert(make_pair(words[0], true));
    
    for(int i=1; i<words.size(); i++){
        if (lastWord != words[i][0] || word.count(words[i]) != 0) {
            answer.push_back(i % n + 1);
            answer.push_back(i/n +1);
            bIncorrect = true;
            break;
        }
        
        word.insert(make_pair(words[i], true));
        
        lastWord = words[i][words[i].length()-1];
    }
    
    if (!bIncorrect){
        answer.push_back(0);
        answer.push_back(0);
    }
    cout <<answer[0] << " " << answer[1];
    return answer;
}