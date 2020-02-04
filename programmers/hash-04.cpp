  
/******************************************************************************
Auther: Jun Soeun(jse525@naver.com)
Date: 2020.02.04
Link: https://programmers.co.kr/learn/courses/30/lessons/42579
result: success
memo: clear
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> sortGenres(vector<string>genres, vector<int>plays) {
    map<string, int> genresMap;
    for(int i = 0 ; i< genres.size(); i++){
        if(genresMap.end()==genresMap.find(genres[i])){
            genresMap[genres[i]] = plays[i];
            //cout<< genres[i] << "|" << plays[i] << endl;
        }
        else{
            genresMap[genres[i]] = genresMap[genres[i]] + plays[i];
            //cout<<genres[i] << "|" << genresMap[genres[i]]<< endl;
        }
    }
    vector<string> sortedGenres;
    while(genresMap.size() > 0){
        map<string, int>::iterator most = genresMap.begin();
        for(map<string, int>::iterator it = genresMap.begin(); it != genresMap.end() ; it++){
            if(it->second > most->second){
                most = it;
            }
        }
        sortedGenres.push_back(most->first);
        genresMap.erase(most);
    }
    return sortedGenres;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    
    vector<string> sortedGenres = sortGenres(genres, plays);
    vector<int> answer;
    for(string g : sortedGenres){
        int mostIndex[2] = {-1,-1};
        int mostPlays[2] = {-1,-1};
        for(int i = 0 ; i< genres.size(); i++){
            if(g == genres[i]){
                if(plays[i] > mostPlays[0]){
                    mostPlays[1] = mostPlays[0];
                    mostIndex[1] = mostIndex [0];
                    mostPlays[0] = plays[i];
                    mostIndex[0] = i;
                    //cout<< "first: " << mostIndex[0] << " " << mostPlays[0]; 
                    continue;
                }
                if(plays[i] > mostPlays[1]){
                    mostPlays[1] = plays[i];
                    mostIndex[1] = i;
                    //cout<< "second: " << mostIndex[1] << " " << mostPlays[1]; 
                    continue;
                }
            }
        }
        answer.push_back(mostIndex[0]);
        //cout<<mostIndex[0]<< " ";
        if( mostIndex[1] != -1){
            answer.push_back(mostIndex[1]);
            //cout<<mostIndex[1];
        }
        //cout<<endl;
    }
    return answer;
}

int main()
{
    string list[] = {"classic", "pop", "classic", "classic", "pop", "gg"};
    int num[] = {500, 600, 150, 800, 2500, 20};
    vector<string> genres;
    for(string g : list){
        genres.push_back(g);
        //cout<< g << " ";
    }
    cout<< endl;
    vector<int> plays;
    for(int n: num){
        plays.push_back(n);       
        //cout<< n << " ";
    }
    
    vector<int> result = solution(genres, plays);
    
    for(int r : result){
        cout << r << " ";
    }
    cout<< endl;
    return 0;
}
