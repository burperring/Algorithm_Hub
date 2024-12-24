#include<vector>
#include<queue>
#include<iostream>

using namespace std;

int n, m;
vector<vector<int>> graph;
int dn[4] = {-1, 1, 0, 0};
int dm[4] = {0, 0, -1, 1};

int maze(int a, int b){
    queue<pair<int, int>> q;
    q.push(make_pair(a,b));
    
    while(!q.empty()){
        int qn = q.front().first;
        int qm = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int mn = qn + dn[i];
            int mm = qm + dm[i];
            
            if(mn < 0 || mn >= n || mm < 0 || mm >= m)
                continue;
            else if(graph[mn][mm] == 0)
                continue;
            else if(graph[mn][mm] == 1){
                graph[mn][mm] = graph[qn][qm] + 1;
                q.push(make_pair(mn, mm));
            }
        }
    }
    
    return graph[n-1][m-1];
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    graph = maps;
    
    answer = maze(0, 0);
    
    if(answer == 1)
        answer = -1;
    
    return answer;
}