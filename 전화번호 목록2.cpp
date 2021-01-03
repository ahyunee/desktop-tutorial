#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phoneBook) {
    bool answer = true;

    sort(phoneBook.begin(), phoneBook.end());
    // 이미 정렬된 값이므로, 옆에 원소랑만 비교하면 됨.
    for ( int i = 0 ; i < phoneBook.size() - 1 ; i++ )
    {
        if ( phoneBook[i] == phoneBook[i+1].substr(0, phoneBook[i].size()) )
        {
            answer = false;
            break;
        }
    }

    return answer;
}