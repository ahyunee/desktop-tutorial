#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    // arr size = 렬 / arr[0].size() = 행
    // 결과 행렬의 길이 -> arr1 행 * arr2열
    
   cout << "결과 행렬 :"<<arr1.size()<<"*"<<arr2[0].size()<<"\n";
    
    for (int k = 0; k < arr1.size(); k++)
    {
        //cout<<k<<"\n";
        vector <int> tmp ;
        for (int i = 0; i < arr2[0].size(); i++) 
        {
            int elmt = 0;
            for (int j = 0; j < arr1[0].size(); j++)
            {
                //cout << arr1[k][j]<<"*"<<arr2[j][i]<<" ";
                elmt += arr1[k][j] * arr2[j][i];
            }
             //cout << "\n";
           // cout << elmt <<" ";
            tmp.push_back(elmt);
        }
        answer.push_back(tmp);
        //cout << "\n";
    }
    return answer;
}