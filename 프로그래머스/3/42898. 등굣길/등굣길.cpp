#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> vCnt(101, vector<int>(101));

int solution(int m, int n, vector<vector<int>> puddles) {
    vCnt[1][1] = 1;
    
    for(auto x : puddles){
        vCnt[x[1]][x[0]] = -1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int a = 0;
            int b = 0;
            if(vCnt[i][j] == -1)
                continue;
            if(vCnt[i-1][j] != -1)
                a = vCnt[i-1][j];
            if(vCnt[i][j-1] != -1)
                b = vCnt[i][j-1];
            vCnt[i][j] += (a + b) % 1000000007;
        }
    }
    
    return vCnt[n][m];
}