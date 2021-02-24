#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

bool findSosu(int n)
{
    if (n == 1 || n==0)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int findPermutationAndNumOfSosu(string &snumber, unordered_map<int, bool> &numset)
{
    int cnt = findSosu(stoi(snumber));
    
    sort(snumber.begin(), snumber.end());
    do
    {
        if (numset.count(stoi(snumber)) == 0)
        {
            numset.insert(make_pair(stoi(snumber), true));
            if (findSosu(stoi(snumber)))
            {
                cnt++;
            }
        }

    } while (next_permutation(snumber.begin(), snumber.end()));

    return cnt;
}

int solution(string numbers)
{
    int answer = 0;
    unordered_map<int, bool> numset;

    for (int i = 0; i < numbers.size(); i++)
    {
        vector<int> vNumset;

        for (int j = 0; j < i; j++)
        {
            vNumset.push_back(0);
        }
        for (int j = i; j < numbers.size(); j++)
        {
            vNumset.push_back(1);
        }
        sort(vNumset.begin(), vNumset.end());
        
       
        do
        {
            string chappedNum = "";
            for (int k = 0; k < vNumset.size(); k++)
            {
                if (vNumset[k] == 1)
                {
                    chappedNum += numbers[k];
                }
            }
            
            if (numset.count(stoi(chappedNum)) == 0)
            {
                numset.insert(make_pair(stoi(chappedNum), true));
                
                answer += findPermutationAndNumOfSosu(chappedNum, numset);
            }
        } while (next_permutation(vNumset.begin(), vNumset.end()));
    }

    return answer;
}