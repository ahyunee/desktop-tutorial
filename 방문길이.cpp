#include <string>
#include <iostream>
#define DIR_L 0
#define DIR_R 1
#define DIR_U 2
#define DIR_D 3

using namespace std;


int solution(string dirs)
{
    int answer = 0;
    bool check[11][11][4] = {false};
    int MAX_LEN = 10;
    int x = 5, y = 5;
    string movDir = "";
    
    for (int i = 0; i < dirs.length(); i++)
    {
        switch (dirs[i])
        {
        case 'L':
            if (y - 1 < 0)
            {
                break;
            }
            if (!check[x][y][DIR_L])
            {
                answer++;
                check[x][y][DIR_L] = true;
                check[x][y - 1][DIR_R] = true;
                movDir+=dirs[i];
            }
            y = y - 1;
            break;
        case 'R':
            if (y + 1 > MAX_LEN)
            {
                break;
            }
            if (!check[x][y][DIR_R])
            {
                answer++;
                check[x][y][DIR_R] = true;
                check[x][y + 1][DIR_L] = true;
                movDir+=dirs[i];
            }
            y = y + 1;
            break;
        case 'U':
            if (x + 1 > MAX_LEN)
            {
                break;
            }
            if (!check[x][y][DIR_U])
            {
                answer++;
                check[x][y][DIR_U] = true;
                check[x + 1][y][DIR_D] = true;
                movDir+=dirs[i];
            }
            x = x + 1;
            break;
        case 'D':
            if (x - 1 < 0)
            {
                break;
            }
            if (!check[x][y][DIR_D])
            {
                answer++;
                check[x][y][DIR_D] = true;
                check[x - 1][y][DIR_U] = true;
                movDir+=dirs[i];
            }
            x = x - 1;
            break;
        }
    }

    cout<<movDir;
    return answer;
}