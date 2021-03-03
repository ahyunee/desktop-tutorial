#include <string>
#include <iostream>
#define DIR_L 0
#define DIR_R 1
#define DIR_U 2
#define DIR_D 3
#define MAX_LEN 10
using namespace std;

int solution(string dirs)
{
    int answer = 0;
    bool check[11][11][4] = {false};
    int x = 5, y = 5;
    int nx=x, ny=y;
    int nDIR= 0, rnDIR= 0; // 현재 방향, 다음 노드의 역방향

    for (int i = 0; i < dirs.length(); i++)
    {
        switch (dirs[i])
        {
        case 'L':
            ny= y-1;
            nDIR = DIR_L;
            rnDIR = DIR_R;
            break;
        case 'R':
            ny= y+1;
            nDIR = DIR_R;
            rnDIR = DIR_L;
            break;
        case 'U':
            nx= x+1;
            nDIR = DIR_U;
            rnDIR = DIR_D;
            break;
        case 'D':
            nx= x-1;
            nDIR = DIR_D;
            rnDIR = DIR_U;
            break;
        }

        if( nx<0 || ny<0 || nx>MAX_LEN || ny>MAX_LEN){
            nx=x, ny=y; // 원상복구
            continue;
        }
        
        if (!check[x][y][nDIR])
        {
            answer++;
            check[x][y][nDIR] = true;
            check[nx][ny][rnDIR] = true;
        }
        
        x=nx, y=ny;
    }

    return answer;
}