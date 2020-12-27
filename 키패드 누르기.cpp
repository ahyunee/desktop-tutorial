#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

/* 
목표 위치, 현재 위치가 정해져 있을 때 가까운 쪽 손 리턴 
return: 오른손잡이(0), 왼손잡이(1)
*/
int findHand(int pX, int pL, int pR, int type){
    // 상하좌우로 움직일수 있으므로, 움직여야하는 거리=(절댓값)x1-x2 + (절댓값)y1-y2
    int dt_L = abs(pL/3-pX/3)+abs(pL%3-pX%3);
    int dt_R = abs(pR/3-pX/3)+abs(pR%3-pX%3);

    if(dt_L == dt_R){ // 거리가 같을 때
        return type;
    }
    else if(dt_L > dt_R){
        return 0;
    }else {
        return 1;
    }
}


string solution(vector<int> numbers, string hand) {
    string answer = "";
    /* 오른손(#) 왼손(*) 초기위치 셋팅
       1 2 3     0 1 2     (0,0) (0,1) (0,2)
       4 5 6     3 4 5     (1,0) (1,1) (1,2)
       7 8 9     6 7 8     (2,0) (2,1) (2,2)
       * 0 #    9 10 11    (3,0) (3,1) (3,2)
    */
    int pL=10;
    int pR=12;
    int bHand = (hand=="right") ? 0:1;
    
    for(int i:numbers){
        switch(i){
            // 가운데 키패드일 때 (어느손으로 누를지 찾아야함)
            case 0:
            case 2:
            case 5:
            case 8:
                if (i==0) i=11;
                if (findHand(i-1, pL-1, pR-1, bHand) == 0){ // 오른쪽으로 누를때
                    pR=i;
                    answer+="R";
                }
                else{ // 왼쪽으로 눌렀을 때
                    pL=i;
                    answer+="L";
                }
                break;
            // 키패드 1행 혹은 3행일 땐 어느손으로 누를 지 구해줄 필요 없음.
            case 1:
            case 4:
            case 7:
                pL=i;
                answer+="L";
                break;
            case 3:
            case 6:
            case 9:
                pR=i;
                answer+="R";
                break;
            default:
                break;
        }
    }
    
    return answer;
}