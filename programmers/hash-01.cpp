/*********
Auther: Jun Soeun(jse525@naver.com)
Date: 2020.01.16
Link: https://programmers.co.kr/learn/courses/30/lessons/42576
result: success
memo: map은 자동정렬이라 비효율적인데 hash_map은 정식 STL이 아니라서 못썻다.
*********/


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> finish;
    for(string p : participant){
        if(finish.count(p)){
            finish[p]++;
        }else{
            finish.insert({{p,1}});
        }
    }
    
    for(string c : completion){
        if(finish.count(c) && finish.find(c)-> second > 1){
            finish.find(c)->second--;
        }else{
            finish.erase(finish.find(c));
        }
    }
    
    for(map<string, int>::iterator it = finish.begin(); it != finish.end(); it++){
        answer = answer  + it->first ;
    }
    
    return answer;
}
int main(){
    vector<string> participant;
    string participantList[] = {"a", "b", "c", "d", "c", "1", "2"};
    participant.insert(participant.begin(), participantList, participantList+7);
    for(string i:participant){
        cout << i << " ";
    }
    cout << endl;
    vector<string> completion;
    string completionList[] = {"a", "b", "c", "1", "2"};
    completion.insert(completion.begin(), completionList, completionList+5);
    for(string i:completion){
        cout << i << " ";
    }
    cout<< endl;
   cout << solution(participant, completion);
    return 0;
}
