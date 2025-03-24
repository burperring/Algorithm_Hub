#include <string>
#include <vector>

using namespace std;

void Hanoi(vector<vector<int>>& answer, int n, int start, int dest){
    if(n == 1){
        answer.push_back({start, dest});
        return;
    }
    
    // 출발지 기둥 -> start(1, 2, 3 중 하나)
    // 도착지 기둥 -> dest(1, 2, 3 중 하나)
    // 나머지 기둥 -> 6 - start - dest(기둥의 번호는 1, 2, 3 이므로)
    Hanoi(answer, n - 1, start, 6 - start - dest);
    answer.push_back({start, dest});
    Hanoi(answer, n - 1, 6 - start - dest, dest);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    Hanoi(answer, n, 1, 3);
    return answer;
}