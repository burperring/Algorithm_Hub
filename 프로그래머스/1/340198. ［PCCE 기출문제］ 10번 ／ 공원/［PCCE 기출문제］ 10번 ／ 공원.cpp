#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool sizeCheck(int mat_size, vector<vector<string>> park){
    bool ok = true;
    int park_row, park_col;
    park_row = park.size();
    park_col = park[0].size();
    
   for(int l = 0; l <= park_row - mat_size; l++) {
        for(int k = 0; k <= park_col - mat_size; k++) {
            ok = true;
            for(int i = 0; i < mat_size; i++) {
                for(int j = 0; j < mat_size; j++) {
                    if (park[i + l][j + k] != "-1") {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (ok) return true;
        }
    }
    return false;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    sort(mats.begin(), mats.end());
    
    for(auto x : mats){
        bool check = sizeCheck(x, park);
        if(check)
            answer = x;
    }
    
    /*
    vector<int> v(park.size());
    
    for(int i = 0; i < park.size(); i++){
        int check = 0;
        int cnt = 0;
        for(auto y : park[i]){
            if(y == "-1"){
                cnt++;
            }
            else{
                check = check > cnt ? check : cnt;
                cnt = 0;
            }
        }
        check = check > cnt ? check : cnt;
        v[i] = check;
    }
    
    for(int i = 0; i < mats.size(); i++){
        int check = 0;
        int cnt = 0;
        for(auto x : v){
            if(mats[i] <= x)
                cnt++;
            else{
                check = check > cnt ? check : cnt;
                cnt = 0;
            }
        }
        check = check > cnt ? check : cnt;
        
        if(check >= mats[i])
            return mats[i];
    }*/
    
    return answer;
}