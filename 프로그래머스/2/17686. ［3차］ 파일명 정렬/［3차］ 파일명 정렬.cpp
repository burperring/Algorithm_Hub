#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
    vector<string> answer;
    map<string, map<int, vector<string>>> smp;
    
    for(auto& file : files)
    {
        int num = 0;
        string head = "";
        bool check = false;
        for(int i = 0; i < file.length(); i++)
        {
            if(file[i] > 47 && file[i] < 58)
            {
                check = true;
                num = num * 10 + (file[i] - '0');
            }
            else if(check == true)
            {
                break;
            }
            else
            {
                head += file[i];
            }
        }
        
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        smp[head][num].push_back(file);
    }
    
    for(auto& x : smp)
    {
        for(auto& h : x.second)
        {
            for(auto& s : h.second)
            {
                answer.push_back(s);
            }
        }
    }
    
    return answer;
}