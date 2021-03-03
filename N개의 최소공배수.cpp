#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include<cmath>
//3,4,9,16 ==> 144

using namespace std;
int nPrimeSet[100] = {0};

void findPrime(int n){
    
    for(int i=2; i<=n; i++){
        int cnt = 0; // 소인수 n승
        
        while(n%i == 0){
            n=n/i;
            cnt++;
        }
        
        if(nPrimeSet[i] < cnt){
            nPrimeSet[i] = cnt;
        }
    }
}

int solution(vector<int> arr) {
    int answer = 1;
    // 소인수 분해 결과의 한 소인수 중에서 지수가 가장 큰 수를 찾아 서로 곱한다
    
    for(int i=0; i<arr.size(); i++){
        findPrime(arr[i]);
    }
    
    for(int i=0; i<100; i++){
        if (nPrimeSet[i] != 0){
            answer = answer * pow(i, nPrimeSet[i]);
        }
    }
    
    return answer;
}