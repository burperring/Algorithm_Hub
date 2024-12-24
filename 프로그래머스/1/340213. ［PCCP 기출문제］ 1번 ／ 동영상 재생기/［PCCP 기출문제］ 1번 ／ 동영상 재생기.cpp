#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    for(auto x : commands){
        if(op_start <= pos && pos <= op_end)
            pos = op_end;
        
        if(x == "next"){
            pos[3] = pos[3] + 1;
            
            if(pos[3] == '6'){
                pos[1] = pos[1] + 1;
                pos[3] = '0';
                
                if(pos[1] == '6'){
                    pos[0] = pos[0] + 1;
                    pos[1] = '0';
                }
            }
            
            if(video_len <= pos)
                pos = video_len;
        }
        else if(x == "prev"){
            pos[3] = pos[3] - 1;
            
            if(pos[3] == '/'){
                pos[1] = pos[1] - 1;
                pos[3] = '5';
                
                if(pos[1] == '/'){
                    pos[0] = pos[0] - 1;
                    pos[1] = '9';
                    
                    if(pos[0] == '/')
                        pos = "00:00";
                }
            }
        }
    }
    
    if(op_start <= pos && pos <= op_end)
        pos = op_end;
    
    return pos;
}