#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());

    
    for(int i=0;i<phone_book.size();i++){
        for(int j=i+1; j<phone_book.size(); j++){
            // 문자열 앞자리 같으면 비교 (이미 정렬된 문자열)
            if(phone_book[i][0] == phone_book[j][0])
            {
                string str = phone_book[j].substr(0, phone_book[i].length());
                cout<<str;
                if(phone_book[i] == str)
                {
                    answer = false;
                    return answer;
                }
            }
            // 문자열 다르면 뛰어 넘기
            else{
                i=j;
                break;
            }
        }

    }
    return answer;
}