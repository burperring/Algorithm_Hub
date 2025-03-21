#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int maze(vector<string> maps, pair<int, int> start, pair<int, int> end){
    vector<vector<int>> v(maps.size(), vector<int>(maps[0].length(), 0));
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].length(); j++){
            if(maps[i][j] == 'X')
                v[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;

        q.pop();
        
        for(int i = 0; i < 4; i++){
            int mx = qx + dx[i];
            int my = qy + dy[i];
            
            if(mx < 0 || mx >= v.size() || my < 0 || my >= v[0].size())
                continue;
            else if(v[mx][my] == -1) 
                continue;
            else if(v[mx][my] == 0){
                v[mx][my] = v[qx][qy] + 1;
                q.push(make_pair(mx, my));
            }
        }
    }
    
    if(v[end.first][end.second] == 0)
        return -1;
    return v[end.first][end.second];
}

int solution(vector<string> maps) {
    int answer = 0;
    pair<int, int> start;
    pair<int, int> lav;
    pair<int, int> end;
    
    for(int i = 0; i < maps.size(); i++){
        for(int j = 0; j < maps[i].length(); j++){
            if(maps[i][j] == 'S'){
                start.first = i;
                start.second = j;
            }
            else if(maps[i][j] == 'L'){
                lav.first = i;
                lav.second = j;
            }
            else if(maps[i][j] == 'E'){
                end.first = i;
                end.second = j;
            }
        }
    }
    
    int stol = maze(maps, start, lav);
    int ltoe = maze(maps, lav, end);
    
    if(stol == -1 || ltoe == -1)
        return -1;
    
    return stol + ltoe;
}