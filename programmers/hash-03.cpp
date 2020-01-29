/******************************************************************************

Auther: Jun Soeun(jse525@naver.com)
Date: 2020.01.29
Link: https://programmers.co.kr/learn/courses/30/lessons/42578
result: success
memo: 몇시간 걸렷는지 파악 불가능. 아이디어는 쉽게 나왓고 그대로 실행.(10:00 ~ 16:00)

*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> clothesMap;
    for(vector<string> cloth : clothes){
        //cout<< cloth[0] << " "<< cloth[1] << " / ";
        string type = cloth[1];
        map<string,int>::iterator it = clothesMap.find(type);
        if(it != clothesMap.end()){
            it->second++;
        }else{
            clothesMap[type] = 1;
        }
    }
    int answer = 1;
    for(map<string, int>::iterator i = clothesMap.begin(); i != clothesMap.end(); i++){
        //cout << i-> first << " " << i->second << endl;
        answer *=  (i->second + 1);
    }
    return answer-1;
}

int main() {
    
    string clothesArray[4][2] = { {"1213", "a"},{"3213", "b"},{"434", "a"}, {"5325", "d"}};

    vector<vector<string>> clothes;
    for(string* c : clothesArray){
        vector<string> cloth;
        cloth.push_back(c[0]);
        cloth.push_back(c[1]);
        clothes.push_back(cloth);
    }
    
    int result = solution(clothes);
    cout<< result;
    return 0;
}
