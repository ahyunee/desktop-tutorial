#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> cache;
int solution(int cacheSize, vector<string> cities) {
 
    int answer = 0;
 
    for (int i = 0; i < cities.size();i++) {                //도시이름 소문자화
        for (int j = 0; j < cities[i].size();j++) {
            if ('A' <= cities[i][j] && cities[i][j] <= 'Z') {
                cities[i][j] += 32;
            }
        }
    }
    vector<string>::iterator it;
 
    for (string x : cities) {
 
        it = find(cache.begin(), cache.end(), x);
 
        if (cacheSize == 0) {
            answer += 5;
        }
        else {// cacheSize > 0
            if (it == cache.end()) {     //cache에 없으면
                answer += 5;
                if (cache.size() < cacheSize) {    //cache 자리 남으면
                    cache.emplace_back(x);
                }
                else {    //cache 자리 없으면
                    cache.erase(cache.begin());    //맨 앞 노드를 제거한다.
                    cache.emplace_back(x); //새로운 노드를 맨 뒤에 추가한다.
                }
            }
            else { //cache에 있으면
                answer += 1;
                cache.erase(it);    //해당 노드 삭제
                cache.emplace_back(x); //새로운 노드를 맨 뒤에 추가한다.(방문 순서 업데이트)
            }
        }
    }
 
    return answer;
}
