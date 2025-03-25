#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    vector<bool> vb(cards.size(), false);
    vector<int> vScore;
    
    while(find(vb.begin(), vb.end(), false) != vb.end()){
        int num;
        int cnt = 0;
        for(int i = 0; i < vb.size(); i++){
            if(!vb[i]){
                num = i;
                break;
            }
        }
        
        while(!vb[num]){
            vb[num] = true;
            num = cards[num] - 1;
            cnt++;
        }
        
        vScore.push_back(cnt);
    }
    
    sort(vScore.begin(), vScore.end(), greater<int>());
    if(vScore.size() >= 2)
        answer = vScore[0] * vScore[1];
    
    return answer;
}