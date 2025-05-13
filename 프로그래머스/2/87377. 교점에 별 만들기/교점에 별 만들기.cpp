#include <string>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<int, int>> spot;
    int max_x = INT32_MIN, min_x = INT32_MAX;
    int max_y = INT32_MIN, min_y = INT32_MAX;
    
    for(int i = 0; i < line.size(); i++){
        for(int j = i + 1; j < line.size(); j++){
            int num = line[i][0] * line[j][1] - line[i][1] * line[j][0];
            if(num){
                ll x = (1LL * line[i][1] * line[j][2] - 1LL * line[i][2] * line[j][1]);
                ll y = (1LL * line[i][2] * line[j][0] - 1LL * line[i][0] * line[j][2]);
                if(x % num == 0 && y % num == 0) spot.insert(make_pair(x / num, y / num));
            }
        }
    }
    
    for(auto x : spot){
        min_x = min(min_x, x.first);
        max_x = max(max_x, x.first);
        min_y = min(min_y, x.second);
        max_y = max(max_y, x.second);
    }
    
    int xSize = max_x - min_x;
    int ySize = max_y - min_y;
    
    for(int i = 0; i <= ySize; i++){
        string s(xSize + 1, '.');
        answer.push_back(s);
    }
    
    for(auto x : spot){
        answer[-x.second + max_y][x.first - min_x] = '*';
    }
    
    return answer;
}