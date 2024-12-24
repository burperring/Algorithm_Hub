#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> vTime;
    int x1 = 1;
    
    for(int i = 0; i < progresses.size(); i++){
        int x;
        x = (100 - progresses[i] + speeds[i] - 1) / speeds[i];  // 양수 나눗셈 올림 공식 -> (x + y -1) / y
        vTime.push_back(x); 
    }
    
    for(int i = 0; i < vTime.size(); i++){
        if(i == 0)
            answer.push_back(1);
        else{
            if(vTime[i-x1] >= vTime[i]){
                answer.back()++;
                x1++;
            }
            else{
                answer.push_back(1);
                x1 = 1;
            }
        }
    }
    
    return answer;
}