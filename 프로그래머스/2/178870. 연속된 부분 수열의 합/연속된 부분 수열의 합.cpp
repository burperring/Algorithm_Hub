#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int start = 0, end = 0, sum = sequence[0];
    vector<int> answer = {0, 1000001};
    
    while(end <= sequence.size()){
        if(sum == k){
            if(answer[1] - answer[0] > end - start){
                answer[1] = end;
                answer[0] = start;
            }
            
            sum -= sequence[start];
            start++;
            end++;
            sum += sequence[end];
        }
        else if(sum < k){
            end++;
            sum += sequence[end];
        }
        else{
            if(start == end){
                start++;
                end++;
                sum = sequence[end];
            }
            else{
                sum -= sequence[start];
                start++;
            }
        }
    }
    
    return answer;
}