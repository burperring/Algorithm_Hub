#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int iTime = 0;

struct comp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int jSize = jobs.size();
    
    priority_queue<pair<int,int>,vector<pair<int,int>>, comp> qDisk;
    
    sort(jobs.begin(), jobs.end());
    
    while(1){
        if(jobs.size() == 0 && qDisk.size() == 0)
            return answer / jSize;
        else if(jobs.size() != 0 && qDisk.size() == 0){
            answer += jobs[0][1];
            iTime = jobs[0][0] + jobs[0][1];
            jobs.erase(jobs.begin());
        }
        else{
            answer += (iTime + qDisk.top().second - qDisk.top().first);
            iTime += qDisk.top().second;
            qDisk.pop();
        }
            
        int check = 0;
        
        for(auto x : jobs){
            if(x[0] <= iTime){
                qDisk.push({x[0],x[1]});
                check++;
            }
        }
        
        jobs.erase(jobs.begin(), jobs.begin() + check);
    }
}