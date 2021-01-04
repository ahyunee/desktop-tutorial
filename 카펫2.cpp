#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {

    int len = brown / 2 + 2; // w+h 길이
    /*  w*h = b+y
        y = (w-2)*(h-2)
        w*h = b+(w-2)*(h-2)
            = b+w*h-2w-2h+4
        2(w+h) = b+4
        w+h = b*(1/2) +2     
    */
    int w = len - 3;
    int h = 3; // 최소 세로 길이는 3 (노란카펫 최소높이1에 감싸면 +2)

    while(w >= h){
        if(w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}