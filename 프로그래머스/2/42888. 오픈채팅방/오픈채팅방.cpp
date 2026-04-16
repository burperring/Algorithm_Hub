#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string, string>> q;      // uid, 행동
    unordered_map<string, string> m;    // uid, 닉네임
    
    for(auto x : record)
    {
        stringstream ss(x);
        
        string temp;
        vector<string> answer;
        while (ss >> temp)
        {
            answer.push_back(temp);
        }
        
        if(answer[0] == "Enter")
        {
            q.push(make_pair(answer[1], answer[0]));
            m[answer[1]] = answer[2];
        }
        else if(answer[0] == "Leave")
        {
            q.push(make_pair(answer[1], answer[0]));
        }
        else
        {
            m[answer[1]] = answer[2];
        }
    }
    
    while(!q.empty())
    {
        pair<string, string> pf = q.front();
        string state = pf.second == "Enter" ? "들어왔습니다." : "나갔습니다.";
        
        string s = m[pf.first] + "님이 " + state;
        answer.push_back(s);
        q.pop();
    }
    
    return answer;
}