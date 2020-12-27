#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    bool isOdd = true;
    for(int i=0;i<n;i++){
        if(isOdd){
            answer+="수";
        }
        else{
            answer+="박";
        }
        isOdd = !isOdd;
    }
    return answer;
}