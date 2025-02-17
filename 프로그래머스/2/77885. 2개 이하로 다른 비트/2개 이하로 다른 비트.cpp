#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for(auto x : numbers){
        if(x % 2 == 0)
            answer.push_back(x + 1);
        else{
            long long bit = 1;
            
            while(1){
                if((x & bit) == 0) break;
                bit *= 2;
            }
            
            bit = bit / 2;
            answer.push_back(x + bit);
        }
    }
    
    return answer;
}