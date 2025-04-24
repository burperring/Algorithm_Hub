#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<string> a, vector<string> b){
    return a[1] < b[1];
}

int startTime(string a){
    int h = stoi(a.substr(0,2));
    int m = stoi(a.substr(3,2));
    
    return h * 60 + m;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> s;
    string work;
    int sTime, leftTime;
    
    sort(plans.begin(), plans.end(), cmp);
    
    work = plans[0][0];
    sTime = startTime(plans[0][1]);
    leftTime = stoi(plans[0][2]);
    
    for(int i = 1; i < plans.size(); i++){
        int workTime = startTime(plans[i][1]);
        int checkTime = sTime + leftTime;
        
        if(checkTime <= workTime){
            answer.push_back(work);
            
            while(!s.empty()){
                string sWork = s.top().first;
                int stackTime = s.top().second;
                s.pop();
                
                if(checkTime + stackTime <= workTime){
                    checkTime += stackTime;
                    answer.push_back(sWork);
                }
                else{
                    stackTime = (checkTime + stackTime) - workTime;
                    s.push({sWork, stackTime});
                    break;
                }
            }
        }
        else{
            int inTime = checkTime - workTime;
            s.push({work, inTime});
        }
        
        work = plans[i][0];
        sTime = startTime(plans[i][1]);
        leftTime = stoi(plans[i][2]);
    }
    
    answer.push_back(work);
    
    while(!s.empty()){
        work = s.top().first;
        s.pop();
        
        answer.push_back(work);
    } 
    
    return answer;
}