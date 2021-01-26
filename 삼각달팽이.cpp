#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n)
{
    vector<int> answer;
    int snale[500502]={0}; // n 최대 1000

    int dir = 0;  // 0: 아래, 1: 오른쪽, 2:위
    int idx = 1; // 현재 idx
    int num = 1;
    int pls = 0;

    for (int i = 0, j = n; i < n; i++)
    {
        switch (dir)
        {
        case 0:
            for (int k = 0; k < j; k++)
            {
                idx = idx + pls;
                snale[idx] = num++;
                pls++;
            }
            break;
        case 1:
            for (int k = 0; k < j; k++)
            { 
                idx++;
                snale[idx] = num++;
               
            }
            break;
        case 2:
            for (int k = 0; k < j; k++)
            {
               idx = idx - pls;
               snale[idx] = num++;+
                pls--;
            }
            break;
        default:
            break;
        }
        
        j--;
        dir++;
        if (dir == 3)
        {
            dir = dir % 3;
        }
    }
   for (int i=1; i<num; i++){
       answer.push_back(snale[i]);
    }
    return answer;
}