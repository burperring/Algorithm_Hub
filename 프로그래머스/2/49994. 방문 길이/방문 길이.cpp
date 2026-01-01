#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void Move(pair<int, int>& pp, char c)
{
    switch(c)
    {
    case 'U':
        pp.first += 1;
        pp.first = pp.first > 5 ? 5 : pp.first;
        break;
    case 'D':
        pp.first -= 1;
        pp.first = pp.first < -5 ? -5 : pp.first;
        break;
    case 'L':
        pp.second -= 1;
        pp.second = pp.second < -5 ? -5 : pp.second;
        break;
    case 'R':
        pp.second += 1;
        pp.second = pp.second > 5 ? 5 : pp.second;
        break;
    default: break;
    }
}

int solution(string dirs) {
    int answer = 0;
    bool check = false;
    pair<int, int> sp;
    pair<int, int> ep {0, 0};
    map<pair<int, int>, set<pair<int, int>>> mp;
    
    for(int i = 0; i < dirs.length(); i++)
    {
        sp = ep;
        Move(ep, dirs[i]);
        if(sp == ep) continue;
        
        if(find(mp[sp].begin(), mp[sp].end(), ep) == mp[sp].end())
        {
            answer++;
            mp[sp].insert(ep);
            mp[ep].insert(sp);
        }
    }
    
    return answer;
}