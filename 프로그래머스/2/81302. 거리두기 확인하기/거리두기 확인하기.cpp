#include <string>
#include <vector>

using namespace std;

int check(vector<string> s){
    vector<pair<int, int>> v;
    
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s[i].length(); j++){
            if(s[i][j] == 'P'){
                v.push_back(make_pair(i, j));
            }
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            int x = abs(v[i].first - v[j].first);
            int y = abs(v[i].second - v[j].second);
            
            if(x + y == 1) return 0;    // 바로 옆에 붙어 있는 경우
            else if(x + y == 2){
                if(v[i].first == v[j].first){   // y축이 같은 경우
                    int mid = (v[i].second + v[j].second) / 2;
                    if(s[v[i].first][mid] == 'O') return 0;
                }
                else if(v[i].second == v[j].second){    // x축이 같은 경우
                    int mid = (v[i].first + v[j].first) / 2;
                    if(s[mid][v[i].second] == 'O') return 0;
                }
                else{   // 대각선인 경우
                    if(s[v[i].first][v[j].second] == 'O' || 
                      s[v[j].first][v[i].second] == 'O') return 0;
                }
            }
        }
    }
    
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto x : places){
        answer.push_back(check(x));
    }
    
    return answer;
}