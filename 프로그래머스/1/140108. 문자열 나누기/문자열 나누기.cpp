#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int X = 1;
    int notX = 0;
    int pivot = 0;
    int num = 1;
    
    while(pivot < s.length()){
        if(s[num] == s[pivot])
            X++;
        else
            notX++;
        
        if(X == notX){
            pivot = num + 1;
            num++;
            X = 1;
            notX = 0;
            answer++;
        }
        
        num++;
        
    }
    
    return answer;
}