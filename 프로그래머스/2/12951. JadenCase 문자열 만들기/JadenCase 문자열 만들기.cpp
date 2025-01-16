#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool bFirst = true;
    
    for(int i = 0; i < s.length(); i++){
        if(bFirst){
            if('a' <= s[i] && s[i] <= 'z')
                s[i] -= 32;
            
            if(s[i] == ' ')
                bFirst = true;
            else
                bFirst = false;
        }
        else if(s[i] == ' '){
            bFirst = true;
        }
        else{
            if('A' <= s[i] && s[i] <= 'Z')
                s[i] += 32;
        }
    }
    
    return s;
}