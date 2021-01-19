#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
    vector<int> cpy = priorities;
    sort(cpy.begin(), cpy.end(), greater<int>());
    // priorities:기존 우선순위, cpy:내림차순으로 정렬된 우선순위

    for (int i = 0, spt = 0; i < priorities.size(); i++)
    {
        // 우선순위가 최댓값일 때 프린트 : 프린트 여부 업데이트(-1), 다음 우선순위 탐색(sp++)
        if (priorities[i] == cpy[spt])
        {
            if (i == location)
            {
                return (spt+1);
            }
            priorities[i] = -1;
            spt++;
        }

        // 끝 위치에 도달했다면, 다시 처음 위치로
        if (i == priorities.size())
        {
            i = -1;
        }
    }
}