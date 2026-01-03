#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> mp {
        {"A", 1}, {"B", 2}, {"C", 3}, {"D", 4}, {"E", 5}, {"F", 6},
        {"G", 7}, {"H", 8}, {"I", 9}, {"J" ,10}, {"K", 11}, {"L", 12},
        {"M", 13}, {"N", 14}, {"O", 15}, {"P" ,16}, {"Q", 17}, {"R", 18},
        {"S", 19}, {"T", 20}, {"U", 21}, {"V" ,22}, {"W", 23}, {"X", 24},
        {"Y", 25}, {"Z", 26}
    };
    
    string sc{};
    int next = 27;
    for(int i = 0; i < msg.length(); i++)
    {
        sc += msg[i];
        string check = sc;
        if(i + 1 != msg.length())
            check += msg[i + 1];
        
        if(check != sc)
        {
            if(mp.find(check) == mp.end())
            {
                mp.insert(make_pair(check, next));
                answer.push_back(mp[sc]);
                sc = "";
                next++;
            }
        }
        else
        {
            answer.push_back(mp[sc]);
        }
    }
    
    return answer;
}