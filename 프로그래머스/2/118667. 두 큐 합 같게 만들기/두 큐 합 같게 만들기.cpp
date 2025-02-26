#include <string>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int limit = queue1.size() * 2 + 1;
    queue<int> q1;
    queue<int> q2;
    long sum1 = accumulate(queue1.begin(), queue1.end(), 0L);
    long sum2 = accumulate(queue2.begin(), queue2.end(), 0L);
    
    for(int i = 0; i < queue1.size(); i++){
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    
    while(!q1.empty() && !q2.empty()){
        if(sum1 == sum2){
            return answer;
        }

        if(answer > limit)
            return -1;
        
        if(sum1 > sum2){
            sum1 -= q1.front();
            sum2 += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else{
            sum1 += q2.front();
            sum2 -= q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        
        answer++;
    }
    
    return -1;
}