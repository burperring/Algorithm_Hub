#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int Time(string a){
    return stoi(a.substr(0, 2)) * 60 + stoi(a.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> v;
    
    for(auto x : book_time){
        v.push_back(make_pair(Time(x[0]), Time(x[1]) + 10));
    }
    
    sort(v.begin(), v.end());
    
    priority_queue<int> q;
    for(int i = 0; i < v.size(); i++){
        if(!q.empty() && -q.top() <= v[i].first)
            q.pop();
        
        q.push(-v[i].second);
    }
    
    answer = q.size();
    
    return answer;
}