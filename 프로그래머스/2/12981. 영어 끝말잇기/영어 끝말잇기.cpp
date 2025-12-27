#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> check;
    
    for(int i = 0; i < words.size() - 1; i++)
    {
        if (check.find(words[i]) != check.end())
        {
            answer.push_back((i + 1) % n == 0 ? n : (i + 1) % n);
            answer.push_back((i / n) + 1);
            break;
        }
        
        if(words[i][words[i].length() - 1] != words[i + 1][0])
        {
            int iwrong = i + 1;
            
            answer.push_back((iwrong + 1) % n == 0 ? n : (iwrong + 1) % n);
            answer.push_back((iwrong / n) + 1);
            break;
        }
        
        check.insert(words[i]);
    }
    
    if (check.find(words.back()) != check.end() && answer.size() == 0)
    {
        answer.push_back(words.size() % n == 0 ? n : words.size() % n);
        answer.push_back((words.size() - 1) / n + 1);
    }
    
    if(answer.size() == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}