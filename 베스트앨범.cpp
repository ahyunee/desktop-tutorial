#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map <string, vector<int>> bestAlbums;
    map <string, int> bestGenres;

    for(int i=0;i<genres.size();i++){
        if(bestAlbums.count(genres[i]) == 0){
            bestAlbums.insert(make_pair(genres[i], i));
            bestGenres.insert(make_pair(genres[i], plays[i]));
        }else if(bestAlbums.count(genres[i]) == 1){
            bestAlbums[genres[i]].push_back(i);
            bestGenres[genres[i]] += plays[i];
        }
        else
        {
            int tmpidx, tmp;
            if (plays[bestAlbums[genres[i]][0]] > plays[bestAlbums[genres[i]][1]]){
                tmp = plays[bestAlbums[genres[i]][0]];
                tmpidx=0;
            }
            else{
                tmp = plays[bestAlbums[genres[i]][1]]; 
                tmpidx=1;
            }
           if (plays[i] > tmp){
               bestAlbums[genres[i]][tmpidx]=i;
           }
           bestGenres[genres[i]] += plays[i];
        }
    }
    
    vector <int> fGenre;
    for (auto it = bestGenres.begin(); it != bestGenres.end(); it++) {
        fGenre.push_back(it->second);
    }
    sort(fGenre.begin(), fGenre.end());
    
    


/*
    int cnt=0;
   for (auto it = bestGenres.begin(); it != bestGenres.end(); it++, cnt++) {
		int s = bestAlbums[it->first].size();
        for(int i=0;i<s;i++){
            answer.push_back(bestAlbums[it->first][i]);
        }
        if (cnt==1){
            break;
        }
	}*/
    return answer;
}