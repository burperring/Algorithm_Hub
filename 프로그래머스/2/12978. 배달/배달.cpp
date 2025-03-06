#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> v(55, vector<pair<int, int>>());
vector<int> Dist;

int Min(int A, int B) {if(A < B) return A; return B;}

void Dijkstra(int N){
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, 1));
    Dist[1] = 0;
    
    while(!PQ.empty()){
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();
        
        for(int i = 0; i < v[Cur].size(); i++){
            int Next = v[Cur][i].first;
            int nCost = v[Cur][i].second;
            
            if(Dist[Next] > Cost + nCost){
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next], Next));
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    Dist.resize(N + 1, 1000000);
    
    for(int i = 0; i < road.size(); i++){
        int N1 = road[i][0];
        int N2 = road[i][1];
        int Dist = road[i][2];
        
        v[N1].push_back(make_pair(N2, Dist));
        v[N2].push_back(make_pair(N1, Dist));
    }
    
    Dijkstra(N);
    for(int i = 1; i <= N; i++){
        if(Dist[i] <= K)
            answer++;
    }
    
    return answer;
}