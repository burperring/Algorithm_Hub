#include <string>
#include <vector>

using namespace std;

char skipCheck(char x, string skip){
    if(skip.find(x) != string::npos)
        x = skipCheck(x + 1 > 'z' ? 'a' : x + 1, skip);
    
    return x;
}

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(auto x : s){
        int num = index;
        
        while(num--){
            x = x + 1 > 'z' ? 'a' : x + 1;
            x = skipCheck(x, skip);
        }
        
        answer += x;
    }
    
    return answer;
}