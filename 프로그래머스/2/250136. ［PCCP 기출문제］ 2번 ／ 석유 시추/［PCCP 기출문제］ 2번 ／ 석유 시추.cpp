#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int solution(vector<vector<int>> land) {
    int answer = 0;
    vector<int> v(land[0].size(), 0);
    queue<pair<int, int>> q;
    
    for(int i = 0; i < land.size(); i++){
        for(int j = 0; j < land[i].size(); j++){
            if(land[i][j] == 1){            // 해당 위치에 석유가 있는 경우
                int gasSize = 0;
                unordered_set<int> s;       // 중복 체크만을 위해 정렬 X
                land[i][j] = 0;
                
                q.push({i, j});
                s.insert(j);
                
                while(!q.empty()){
                    gasSize++;
                    int curY = q.front().first;
                    int curX = q.front().second;
                    q.pop();
                    
                    for(int k = 0; k < 4; k++){
                        int checkY = curY + dy[k];
                        int checkX = curX + dx[k];
                        
                        if(checkY >= land.size())
                            continue;
                        else if(checkY < 0)
                            continue;
                        else if(checkX >= land[0].size())
                            continue;
                        else if(checkX < 0)
                            continue;
                        
                        if(land[checkY][checkX] == 1){
                            land[checkY][checkX] = 0;
                            q.push({checkY, checkX});
                            s.insert(checkX);
                        }
                    }
                }
                
                for(auto l = s.begin(); l != s.end(); l++){
                    v[*l] += gasSize;
                }
            }
            else                             // 해당 위치에 석유가 없는 경우
                continue;
        }
    }
    
    answer = *max_element(v.begin(), v.end());
    
    return answer;
}