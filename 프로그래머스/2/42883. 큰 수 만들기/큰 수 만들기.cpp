#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = number;
    
    while(k != 0){
        for(int i = 0; i < answer.size(); i++){
            if(answer[i] < answer[i + 1]){
                answer.erase(answer.begin() + i);
                break;
            }
            else if(answer[i] > answer[i + 1] && i == answer.size()-2){
                answer.erase(answer.begin() + i + 1);
                cout << i << endl;
                break;
            }
        }
        k--;
    }
    
    return answer;
}