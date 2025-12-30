#include <string>
#include <cstring>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

bool bCheck(deque<string> dqc, string city, int& i)
{
    deque<string>::iterator iter;
    for(iter = dqc.begin(); iter != dqc.end(); iter++)
    {
        const char* c1 = (*iter).c_str();
        const char* c2 = city.c_str();
        int result = strcasecmp(c1, c2);
        if(result == 0)
        {
            i = distance(dqc.begin(), iter);
            return false;
        }
           
    }
    
    return true;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> dqc;
    
    for(auto city : cities)
    {
        int i = 0;
        if(bCheck(dqc, city, i))
        {
            answer += 5;
            dqc.push_back(city);
            
            if(dqc.size() > cacheSize)
            {
                dqc.pop_front();
            }
        }
        else
        {
            answer++;
            dqc.erase(dqc.begin() + i);
            dqc.push_back(city);
        }
           
    }
    
    return answer;
}