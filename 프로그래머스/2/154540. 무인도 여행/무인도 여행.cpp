#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<string> v;

int maze(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    int sum = v[x][y] - '0';
    v[x][y] = 'X';
    
    while(!q.empty()){
        int qx = q.front().first;
        int qy = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int mx = qx + dx[i];
            int my = qy + dy[i];
            
            if(mx < 0 || mx >= v.size() || my < 0 || my >= v[0].length())
                continue;
            else if(v[mx][my] == 'X')
                continue;
            else{
                sum += v[mx][my] - '0';
                v[mx][my] = 'X';
                q.push(make_pair(mx, my));
            }
        }
    }
    
    return sum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    v = maps;
    
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].length(); j++){
            if(v[i][j] != 'X'){
                int num = maze(i, j);
                answer.push_back(num);
            }
        }
    }
    
    if(answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}