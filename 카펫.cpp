#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // W >= H
    // brown+yellow = W*H
    // b = yw*2 + yh*2 +4;
    // b = (yw+2)(yh+2)
    // Yellow의 크기만 구하믄댐!
    
    int TotalSize = brown+yellow;
    int y_x=yellow, y_y=1;
    
    while((y_x >= y_y) && ((y_x+2) * (y_y+2) != TotalSize)){
        while (1){
            y_y++;
            if (yellow%y_y == 0) break;
        }
        y_x = yellow/y_y;
    }
    
    answer.push_back(y_x+2);
    answer.push_back(y_y+2);
    return answer;
}