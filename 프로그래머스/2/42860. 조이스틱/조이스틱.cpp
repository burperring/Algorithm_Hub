#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string name) {
    int answer = 0;
    int len = name.size();
    int move = len - 1;
    
    for(int i = 0; i < name.size(); i++){
        answer += min(26 - (name[i] - 'A'), name[i] - 'A');
        
        int ind = i + 1;
        while(ind < len && name[ind] == 'A') ind++;
        
        move = min(move, i + len - ind + min(i, len - ind));
    }

    return answer + move;
}