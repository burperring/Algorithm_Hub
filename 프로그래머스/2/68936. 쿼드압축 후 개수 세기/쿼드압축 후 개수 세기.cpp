#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;

void DFS(int x, int y, int size, vector<int> &answer){
    bool zero, one;
    zero = one = true;
    
    for(int i = x; i < x + size; i++){
        for(int j = y; j < y + size; j++){
            if(map[i][j] == 0) one = false;
            if(map[i][j] == 1) zero = false;
        }
    }
        
    if(zero){
        answer[0]++;
        return;
    }
    if(one){
        answer[1]++;
        return;
    }
    
    DFS(x, y, size / 2, answer);
    DFS(x, y + size / 2, size / 2, answer);
    DFS(x + size / 2, y, size / 2, answer);
    DFS(x + size / 2, y + size / 2, size / 2, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    map = arr;
    DFS(0, 0, arr.size(), answer);
    return answer;
}