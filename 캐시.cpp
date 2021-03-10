#include <string>
#include <vector>
#include <iostream>

#define miss 5
#define hit 1
using namespace std;

void translateLower(string &ori){
    string lowerstr = ori;
    ori = "";
    for(int j=0; j<=lowerstr.length(); j++){
        ori += tolower(lowerstr[j]);
    }
}

void reArrangeHit(vector<int> &order, int hidx){
   vector<int> original = order;
   
    for(int i=hidx; i>=0; i--){
       order[i] = original[i-1];
    }
    
    order[0] = original[hidx];
}

void reArrangeMiss(vector<int> &order, int next){
    vector<int> tmp = order;
    // 앞 인덱스가 젤 최신
    for(int i=0; i< order.size(); i++){
       order[i+1] = tmp[i];
    }
    order[0] = next;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int s_idx=0;
    vector<int> cache, tmp;
    
    if (cacheSize == 0 ){
        return miss*cities.size();
    }
    
    for(int i=0; i< cities.size(); i++){
        translateLower(cities[i]);
    }

    tmp.push_back(0);
    answer = miss;
    for(s_idx=1; s_idx<cities.size(); s_idx++){
        bool isExist = false;
        if (tmp.size() == cacheSize-1){
            break;
        }
        for (int j=0; j<tmp.size(); j++){
            if(cities[tmp[j]] == cities[s_idx]){
                answer += hit;
                reArrangeHit(cache, j);
                isExist = true;
            }
        }
        if(!isExist){
            tmp.push_back(s_idx);
            answer += miss;
        }
    }
    
    
    for(int i=tmp.size()-1; i>=0; i++){
        cache.push_back(tmp[i]);
    }

    for(int i=s_idx; i<cities.size(); i++){
        
        bool isExist = false;
        for(int j=0; j<cacheSize; j++){
            if (cities[cache[j]] == cities[i]){
                answer += hit;
                reArrangeHit(cache, j);
                isExist = true;
                break;
            }
        }
        
        if (!isExist){
            answer += miss;
            reArrangeMiss(cache, i);
        }
    }
    
    
    return answer;
}