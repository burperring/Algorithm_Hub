#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<string, int> mp;
    
    string check = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '{') continue;
        if(s[i] == '}' || s[i] == ',')
        {
            if(mp.find(check) != mp.end())
                mp[check]++;
            else if(check != "")
                mp.emplace(check, 1);
            
            check = "";
            continue;
        }
        
        check += s[i];
    }
    
    vector<pair<string, int>> vec(mp.begin(), mp.end());
    
    sort(vec.begin(), vec.end(), [](const auto &a, const auto &b)
         {
            return a.second > b.second; 
         });
    
    for(auto x : vec)
    {
        int num = stoi(x.first);
        answer.push_back(num);
    }
    
    return answer;
}