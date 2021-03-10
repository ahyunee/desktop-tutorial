#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s)
{
    int min, max;
    string answer;
    bool bFirst = true;
    string tmp = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (bFirst)
            {
                max = stoi(tmp);
                min = stoi(tmp);
                bFirst= false;
            }
            if (stoi(tmp) > max)
            {
                max = stoi(tmp);
            }
            if (stoi(tmp) < min)
            {
                min = stoi(tmp);
            }
            tmp = "";
        }
        else
        {
            tmp += s[i];
        }
    }

    if (stoi(tmp) > max)
    {
        max = stoi(tmp);
    }
    if (stoi(tmp) < min)
    {
        min = stoi(tmp);
    }
    
    return to_string(min)+" "+to_string(max);
}