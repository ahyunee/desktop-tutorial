#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    
    for (int i = 0; i<size; i++)
    {
        // 현재 주시하고 있는 가격(s.top()값이 가르키는 인덱스)보다 떨어졌다면
        while (!s.empty() && prices[s.top()] > prices[i])
        {
            // 시간 계산
            answer[s.top()] = i - s.top();
            s.pop();
        }

        // 스택에 인덱스를 넣어줌
        s.push(i);
    }

    // 스택에 남은 인덱스의 시간 계산해주기 (가격 안 떨어진 숫자들)
    while (!s.empty())
    {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }

    return answer;
}
