#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool check(string s){
    stack<char> sc;
    
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            sc.push(s[i]);
        else{
            if(sc.size() == 0)
                return false;
            if(s[i] == ')'){
                if(sc.top() == '(')
                    sc.pop();
                else
                    return false;
            }
            else if(s[i] == '}'){
                if(sc.top() == '{')
                    sc.pop();
                else
                    return false;
            }
            else{
                if(sc.top() == '[')
                    sc.pop();
                else
                    return false;
            }
        }
    }
    
    if(sc.size() != 0)
        return false;
    
    return true;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++){
        if(check(s))
            answer++;
        string first = s.substr(0, 1);
        string sub = s.substr(1, s.length() - 1);
        s = sub + first;
    }
    
    return answer;
}