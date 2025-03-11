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
        // v[i].first(입장시간)이 q.top 보다 크면
        if(!q.empty() && -q.top() <= v[i].first)
            q.pop(); // 동일한 방 사용이 가능하므로 pop을 통해 제거
        
        // -붙여서 push 하는 이유 (priority_queue 특성 때문에)
        q.push(-v[i].second);
    }
    
    // 큐의 사이즈가 최소로 사용하는 방의 개수
    answer = q.size();
    
    return answer;
}