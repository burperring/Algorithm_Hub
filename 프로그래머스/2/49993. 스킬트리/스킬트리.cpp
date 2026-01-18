#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(auto x : skill_trees)
    {
        int point = 0;
        bool check = true;
        for(int i = 0; i < x.length(); i++)
        {
            size_t pos = skill.find(x[i]);
            if(pos != string::npos)
            {
                if(pos == point)
                    point++;
                else if(pos > point)
                {
                    check = false;
                    break;
                }
            }
        }
        if(check) answer++;
    }
    
    return answer;
}