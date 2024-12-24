#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int channelSize;
vector<vector<string>> vs;

void channel(string start, vector<string> plane, vector<vector<string>> v, vector<string> check){    
    if(vs.size() == 1)
        return;
    
    check.push_back(start);
    
    if(check.size() == channelSize)
        vs.push_back(check);
    
    int x = find(plane.begin(), plane.end(), start) - plane.begin();
    
    for(int i = 0; i < v[x].size(); i++){
        vector<vector<string>> v1 = v;
        start = v[x][i];
        v1[x].erase(v1[x].begin() + i);
        channel(start, plane, v1, check);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> plane;
    vector<string> check;
    vector<vector<string>> v(10001);
    string start = "ICN";
    
    sort(tickets.begin(), tickets.end());
    
    channelSize = tickets.size() + 1;
    
    for(auto x : tickets){
        plane.push_back(x[0]);
        plane.push_back(x[1]);
    }
    
    sort(plane.begin(), plane.end());
    plane.erase(unique(plane.begin(), plane.end()), plane.end());
    
    for(auto x : tickets){
        int i = find(plane.begin(), plane.end(), x[0]) - plane.begin();
        v[i].push_back(x[1]);
    }
    
    channel(start, plane, v, check);
    
    answer = vs[0];

    return answer;
}