#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define pp pair<int, int>

using namespace std;

bool cmp(const pp& a, const pp& b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> m;
    
    for(auto x : tangerine){
        m[x]++;
    }
    
    vector<pp> v(m.begin(), m.end());
    sort(v.begin(), v.end(), cmp);
    
    for(auto x : v){
        answer++;
        k -= x.second;
        if(k <= 0)
            break;
    }
    
    return answer;
}