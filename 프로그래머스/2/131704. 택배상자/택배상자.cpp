#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    queue<int> q;
    stack<int> s;
    
    for(int i = 0; i < order.size(); i++){
        q.push(i + 1);
    }
    
    for(auto x : order){
        while(1){
            if(q.size() > 0 && q.front() == x){
                answer++;
                q.pop();
                break;
            }
            else if(q.size() > 0 && q.front() < x){
                s.push(q.front());
                q.pop();
            }
            else if(s.size() > 0 && s.top() == x){
                answer++;
                s.pop();
                break;
            }
            else return answer;
        }
    }
    
    return answer;
}