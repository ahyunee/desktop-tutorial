#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int sidx = 0; // 비교 시작인덱스
    int cnt = k;
    bool remove[1000000] = {false};
    // 0~k 번째 수에서 젤큰 숫자(i1) 찾음
    // 해당 숫자의 인덱스 찾고 0~해당인덱스(i1) 제거
    // 해당 인덱스 ~ (k-1) 수에서 제일 큰 숫자(i2) 찾음.
    // i1 -i2 인덱스 제거 (~ k갯수를 다 찾을때까지)

    while (cnt > 0 && sidx < number.length())
    {
        int tmp = sidx;
        int end_idx = sidx + cnt;
       // cout << "\nidx=" << sidx << ", cnt=" << cnt << ">>" << number[tmp] << " ";

        for (int i = sidx + 1; i <= end_idx; i++)
        {
            //cout << number[i] << " ";
            if (number[tmp] < number[i])
            {
                tmp = i;
            }
        }

        for (int i = sidx; i < tmp; i++)
        {
            remove[i] = true;
        }
        
        cnt = cnt - (tmp - sidx);
        sidx = tmp + 1;
    }
    

    //cout <<"remove : ";
    for (int i = 0; i < number.length()-cnt; i++)
    {
        //cout <<remove[i]<<" ";
        if (!remove[i])
        {
            answer += number[i];
        }
    }
    
    
    
    return answer;
}