#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int endPoint = 0; // 차례로 100% 달성 체크 변수

    while(1) {
        
        // 작업속도 업데이트
        for(int i=endPoint;i<progresses.size(); i++){
            progresses[i] = progresses[i] + speeds[i];
        }
        
        int cnt = 0; // 한꺼번에 작업 끝나는 갯수 저장 변수

        // 100% 달성률 작업 찾기 : endPoint는 무조건 100% 달성해야
        for (int j=endPoint; j<progresses.size(); j++){
            if (progresses[j]<100){
                break;
            }
            else {
                cnt++;
            }
        }

        // 100% 달성 작업 찾았을 때
        if (cnt!=0){
            // endPoint & answer 업뎃
            endPoint = endPoint + cnt;
            answer.push_back(cnt);
        }
        
        // 모든 작업이 마무리 됐으면 종료처리
        if (endPoint >= progresses.size()){
            break;
        }
    }
    
    return answer;
}