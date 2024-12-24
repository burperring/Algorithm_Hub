#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> sumTriangle(500, vector<int>(500));

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int iSize = triangle.size();
    
    sumTriangle[0][0] = triangle[0][0];
    
    for(int i = 0; i < iSize - 1; i++){
        for(int j = 0; j < i + 1; j++){
            sumTriangle[i+1][j] = max(sumTriangle[i+1][j], sumTriangle[i][j] + triangle[i+1][j]);
            sumTriangle[i+1][j+1] = max(sumTriangle[i+1][j+1], sumTriangle[i][j] + triangle[i+1][j+1]);
        }
    }
    
    for(int i = 0; i < sumTriangle[iSize-1].size(); i++){
        answer = max(answer, sumTriangle[iSize-1][i]);
    }
    
    return answer;
}