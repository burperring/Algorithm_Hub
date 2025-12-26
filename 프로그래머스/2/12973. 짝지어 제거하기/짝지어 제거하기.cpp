#include <iostream>
#include<string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> cs;
    cs.push(s[0]);
    
    for(int i = 1; i < s.length(); i++)
    {
        if(cs.size() == 0)
            cs.push(s[i]);
        else if(cs.top() == s[i])
            cs.pop();
        else
            cs.push(s[i]);
    }
    
    return cs.size() == 0 ? 1 : 0;
}