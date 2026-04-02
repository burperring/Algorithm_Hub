#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    
    for(auto& x : works)
    {
        pq.push(x);
    }
    
    while(n--)
    {
        int num = pq.top();
        num--;
        pq.pop();
        
        if(num != 0) pq.push(num);
        if(pq.empty()) break;
    }
    
    while(!pq.empty())
    {
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    
    return answer;
}