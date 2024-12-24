#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> vCh;
    
    for(int i = 0; i < s.size(); i++){
        if(vCh.empty() && s[i] == ')'){
            answer = false;
            break;
        }
        
        if(s[i] == '(')
            vCh.push_back(s[i]);
        else if(s[i] == ')')
            vCh.pop_back();
    }
    
    if(vCh.size() != 0)
        answer = false;

    return answer;
}