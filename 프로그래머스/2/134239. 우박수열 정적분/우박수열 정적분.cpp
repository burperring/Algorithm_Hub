#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> v;
    v.push_back(k);
    
    while(k != 1){
        if(k % 2 == 0) k /= 2;
        else k = (k * 3) + 1;
        v.push_back(k);
    }
    
    for(auto it : ranges){
        int x1 = it[0];
        int x2 = v.size() - 1 + it[1];
        double size = 0;
        
        for(int i = x1; i < x2; i++){
            size += double(v[i] + v[i + 1]) / 2;
        }
        
        if(x1 > x2) answer.push_back(-1.0);
        else answer.push_back(size);
    }
    
    return answer;
}