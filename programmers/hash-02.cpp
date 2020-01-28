/******************************************************************************

Auther: Jun Soeun(jse525@naver.com)
Date: 2020.01.28
Link: https://programmers.co.kr/learn/courses/30/lessons/42577
result: success
memo: 해쉬문제인데 해쉬로 푼게 아닌기분.. 그냥 비교해서 풀엇다.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map<string, int> numMap;
    for(string p: phone_book){
        for(map<string,int>::iterator m = numMap.begin(); m != numMap.end(); m++){
            int minLength = 0;
            if(p.length() < (m->first).length()){
                minLength = p.length();
            }else{
                minLength = (m->first).length();
            }
            string cutStr = p.substr(0, minLength);
            string cutStr2 = (m->first).substr(0,minLength);
            if(cutStr2 == cutStr){
                cout<< cutStr << " "<< cutStr2 << endl;
                answer = false;
                return answer;
            }
        }
    numMap[p] = 1;
    }
    return answer;
}

int main()
{
    
    
    string pb1[] = { "1919", "049328", "0243","02"};

    vector<string> phone_book;
    
    for(string p : pb1){
        phone_book.push_back(p);
    }
    
    bool result =  solution(phone_book);
    cout<< result;

    return 0;
}
