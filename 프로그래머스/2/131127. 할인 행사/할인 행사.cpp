#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int num = accumulate(number.begin(), number.end(), 0);
    
    for(int i = 0; i <= discount.size() - num; i++){
        unordered_map<string, int> um;
        bool check = true;
        
        for(int j = i; j < i + num; j++){
            um[discount[j]]++;
        }
        
        for(int j = 0; j < want.size(); j++){
            if(um[want[j]] != number[j]){
                check = false;
                break;
            }
        }
        
        if(check)
            answer++;
    }
    
    return answer;
}