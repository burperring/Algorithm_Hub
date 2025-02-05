#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<int> q = priorities;
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    while(1){
        if(q[0] == priorities[0]){
            q.erase(q.begin());
            priorities.erase(priorities.begin());
            answer++;
            if(location == 0) return answer;
            else location--;
        }
        else{
            q.push_back(q[0]);
            q.erase(q.begin());
            location--;
            if(location < 0) location = q.size() - 1;
        }
    }
    
    return answer;
}