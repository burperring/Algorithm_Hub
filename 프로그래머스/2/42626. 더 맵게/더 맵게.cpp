#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> qScov;
    
    for(auto x : scoville){
        qScov.push(x);
    }
    
    while(1){
        if(qScov.top() >= K)
            return answer;
        else if(qScov.size() == 1 && qScov.top() < K){
            answer = -1;
            return answer;
        }
        
        int s1, s2;
        s1 = qScov.top();
        qScov.pop();
        s2 = qScov.top();
        qScov.pop();
        
        int iScovNew = s1 + s2 * 2;
        qScov.push(iScovNew);
        answer++;
    }
    
    return answer;
}