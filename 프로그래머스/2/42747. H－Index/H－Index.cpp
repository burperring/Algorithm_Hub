#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for(int i = 0; i < citations.size(); i++){
        if(citations[i] >= citations.size() - i){
            answer = citations.size() - i;
            return answer;
        }
    }
    
    return answer;
}