#include <vector>
#include <iostream>
using namespace std;
int gm = 0, gn = 0;
vector<int> areaCnt; // 영역의 넓이를 저장하기 위한 변수

void search(int num, int x, int y, int cnt, vector<vector<int>> &picture)
{
    // 배열 범위 체크
    if (x < 0 || y < 0 || x >= gm || y >= gn)
    {
        return ;
    }
    
    // 탐색
    if (picture[x][y] == num)
    {
        picture[x][y] = 0;
        areaCnt[cnt]++;

        // 다음 위치(상하좌우) 탐색
        search(num, x - 1, y, cnt, picture);
        search(num, x + 1, y, cnt, picture);
        search(num, x, y - 1, cnt, picture);
        search(num, x, y + 1, cnt, picture);
    }

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int cnt = 0; // n번째 영역 인덱스 변수
    vector<int> answer(2);

    gm = m, gn = n;
    areaCnt = {0};

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] != 0)
            {
                areaCnt.push_back(0);
                search(picture[i][j], i, j, cnt, picture);
                number_of_area++; // 영역 +1

                // 최대넓이 영역 업데이트
                if (areaCnt[cnt] > max_size_of_one_area)
                {
                    max_size_of_one_area = areaCnt[cnt];
                }
                // 영역 인덱스 증가
                cnt++;
            }
        }
    }

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}