#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
    문자열을 i 단위로 자름 (i는 1씩 늘어남)
    이미 자른 문자열(bstr)과 새로 자른 문자열(nstr) 비교
    - 같을 때: 카운트 증가 
    - 다를 때: cnt + 이미 자른 문자열(bstr) (cnt 값이 1이하면 삭제)
    
    (!마지막 문자열) 새로 자를 문자열이 i단위보다 작을 때는 sp~문자열끝 까지 자름.
    - 마지막 문자열이 같을 때 : 카운트 증가 및 문자열(Chagedstr) 업뎃 (changedstr + bstr)
    - 마지막 문자열이 다를 때 : 마지막에 자른 문자열(nstr) 붙이기.

    i단위로 잘랐을 때 길이랑 answer값 비교 해서 작은값 업뎃
*/

int solution(string s) {
    int answer = s.length();
    // 반복되는 문자열을 구하는 것이므로 단위는 최대 길이의 1/2까지만 해도됨
    for (int i=1; i<= s.length()/2; i++){

        int sp = 0, cnt = 1; // sp:문자열 자를 위치, cnt=동일문자열수
        bool isFin = false;

        string strChanged = ""; // 처리된 문자열 저장 변수
        string bstr = s.substr(sp,i);

        sp = sp + i;
        
        while(1){
            string nstr="";
            if(sp+i >= s.length()){
                nstr = s.substr(sp, s.length()-sp);
                isFin = true;
            }
            else {
                nstr = s.substr(sp, i);
                sp = sp + i;
            }


            if (bstr == nstr){
                cnt++;
                if (isFin){
                    strChanged += (to_string(cnt)+bstr);
                }
            }
            else {
                if (cnt > 1){
                    strChanged += (to_string(cnt)+bstr);
                }
                else {
                    strChanged += bstr;
                }
                
                if (isFin){
                    strChanged += nstr;
                }
                
                bstr = nstr; // bstr 업뎃
                cnt = 1;     // cnt 초기화
            }

            if (isFin){
                break;
            }
        }
        
        if (answer > strChanged.length()){
            answer = strChanged.length();
        }
    }
    
    return answer;
}