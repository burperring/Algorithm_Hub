#include<iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> CType;
    
    for(int i = 0; i < clothes.size(); i++){
        CType[clothes[i][1]]++;
    }
    
    for(auto iter = CType.begin(); iter != CType.end(); ++iter){
        // 안입는 경우 + 1
        answer = answer * (iter->second + 1);
    }

    // 모두 벗은 경우 -1
    answer--;
    
    return answer;
}