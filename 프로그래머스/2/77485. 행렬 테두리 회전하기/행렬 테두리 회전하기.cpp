#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> v(rows + 1, vector<int>(columns + 1));
    
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            v[i][j] = ((i - 1) * columns) + j;
        }
    }
    
    for(auto x : queries){
        int x1 = x[0];
        int y1 = x[1];
        int x2 = x[2];
        int y2 = x[3];
        int mx = x1, my = y1;
        int dir = 0;
        int min = v[x1][y1];
        int num = v[x1][y1];
        
        while(1){
            if(my == y2 && mx == x1)
                dir++;
            if(my == y2 && mx == x2)
                dir++;
            if(mx == x2 && my == y1)
                dir++;
                
            int task = v[mx + dx[dir]][my + dy[dir]];
            v[mx + dx[dir]][my + dy[dir]] = num;
            num = task;
            mx = mx + dx[dir];
            my = my + dy[dir];
            
            min = min > num ? num : min;
            
            if(mx == x1 && my == y1)
                break;
        }
        
        answer.push_back(min);
    }
    
    return answer;
}