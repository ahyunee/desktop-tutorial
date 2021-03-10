#include <string>
#include <vector>

using namespace std;

bool IsCorrect(string p){
    int f=0;
    for(int i=0; i<p.length(); i++){
        if(p[i]=='('){
            f++;
        }
        else if(p[i]==')'){
            f--;
        }
        
        if (f<0){
            return false;
        }
    }
    return true;
}
string ChangeStr(string p){
    if(p=="") return "";
    
    string u="", v="";
    int lcnt=0, rcnt=0;
    for(int i=0; i<p.length(); i++){
        if (p[i]=='(')
            lcnt++;
        else if (p[i]==')')
            rcnt++;
        
        if (lcnt==rcnt){
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    
    if (IsCorrect(u)){
        return u+ChangeStr(v);
    }
    else {
        string tmp = "("+ ChangeStr(v)+")";
        u = u.substr(1, u.length()-2);
        
        for(int i=0; i<u.length(); i++){
            (u[i]=='(') ? tmp+=')': tmp+='(';
        }
        
        return tmp;
    }
}


string solution(string p) {
    string answer = "";
   
    answer = ChangeStr(p);
    return answer;
}