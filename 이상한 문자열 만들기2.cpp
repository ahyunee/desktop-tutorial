#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int nIndex = 1;
    for (int i = 0; i < s.size(); i++, nIndex++)
    {
        if (s[i] == ' ')
        {
            nIndex = 0;
            answer += " ";
        }
        else
            nIndex & 1 ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }

    return answer;
}