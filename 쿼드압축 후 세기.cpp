#include <string>
#include <vector>
#include <iostream>

using namespace std;

void SearchSquare(int n, int x, int y, vector<vector<int>> &arr, int cnt[])
{
    if (n == 1)
    {
        return ;
    }

    // 해당영역이 압축가능한지 체크
    int fnum = arr[x][y];
    bool canMerge = true;

    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (arr[i][j] != fnum)
            {
                canMerge = false;
                break;
            }
        }
    }
    
    if (!canMerge){
        // 압축이 불가능하다면 > 분할해서 탐색
        SearchSquare(n / 2, x, y, arr, cnt);
        SearchSquare(n / 2, x + n / 2, y, arr, cnt);
        SearchSquare(n / 2, x + n / 2, y + n / 2, arr, cnt);
        SearchSquare(n / 2, x, y + n / 2, arr, cnt);
    }
    else {
        // 압축이 가능하다면 > 갯수 업데이트
        cnt[fnum] = cnt[fnum]- n*n+1;
        cout<<"압축 # n="<<n<<" : "<<cnt[0]<<" "<<cnt[1]<<'\n';
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;
    int cnt[2]={0};

    // 0,1 갯수 저장
    for(int i=0;i<arr.size();i++){
        for (int j=0; j<arr[0].size(); j++){
            cnt[arr[i][j]]++;
        }
    }
    cout<<cnt[0]<<" "<<cnt[1]<<'\n';
    SearchSquare(arr.size(), 0, 0, arr, cnt);

    answer.push_back(cnt[0]);
    answer.push_back(cnt[1]);

    return answer;
}
