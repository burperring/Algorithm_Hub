#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int iCol;

bool cmp(vector<int> v1, vector<int> v2){
    if(v1[iCol - 1] == v2[iCol - 1]) return v1[0] > v2[0];
    return v1[iCol - 1] < v2[iCol - 1];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    iCol = col;
    sort(data.begin(), data.end(), cmp);
    
    for(int i = row_begin - 1; i < row_end; i++){
        int num = 0;
        for(auto x : data[i]){
            num += (x % (i + 1));
        }
        answer = answer ^ num;
    }
        
    return answer;
}