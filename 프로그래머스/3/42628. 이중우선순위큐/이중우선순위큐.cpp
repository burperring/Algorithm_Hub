#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> vInt;
    
    for(auto x : operations){
        if(x[0] == 'I'){
            vInt.push_back(stoi(x.substr(2, x.size())));
        }
        else if(x[0] == 'D' && vInt.size() != 0){
            if(x[2] == '1'){
                vInt.erase(max_element(vInt.begin(), vInt.end()));
            }
            else{
                vInt.erase(min_element(vInt.begin(), vInt.end()));
            }
        }
    }
    
    if(vInt.size() == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*max_element(vInt.begin(), vInt.end()));
        answer.push_back(*min_element(vInt.begin(), vInt.end()));
    }

    return answer;
}