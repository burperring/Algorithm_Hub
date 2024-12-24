#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    set<int> sIsland;
    
    sort(costs.begin(), costs.end(), comp);
    
    sIsland.insert(costs[0][0]);
    sIsland.insert(costs[0][1]);
    answer += costs[0][2];
    
    while(sIsland.size() != n){
        for(auto x : costs){
            if(sIsland.find(x[0]) == sIsland.end() && sIsland.find(x[1]) != sIsland.end()){
                sIsland.insert(x[0]);
                answer += x[2];
                break;
            }
            else if(sIsland.find(x[0]) != sIsland.end() && sIsland.find(x[1]) == sIsland.end()){
                sIsland.insert(x[1]);
                answer += x[2];
                break;
            }
        }
    }
    
    return answer;
}