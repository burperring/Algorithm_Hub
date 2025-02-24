#include <string>
#include <vector>
#include <queue>

using namespace std;

int arr[1001][1001];
const int dx[] = {1, 0, -1};
const int dy[] = {0, 1, -1};

vector<int> solution(int n) {
    vector<int> answer;
    
    int i, j, num, cnt, len, dir;
    i = j = num = 1;
    cnt = dir = 0;
    len = n;
    
    while(len > 0){
        arr[i][j] = num++;
        cnt++;
        
        if(cnt == len){
            dir = (dir + 1) % 3;
            cnt = 0;
            len--;
        }
        
        i += dx[dir];
        j += dy[dir];
    }
    
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            if(arr[i][j] != 0)
                answer.push_back(arr[i][j]);
    
    return answer;
}