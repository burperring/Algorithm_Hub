#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long low = 0;
    long long high = n * (long long)times.back();
    
    while(low <= high){
        long long mid = (low + high) / 2;
        long long cnt = 0;
        
        for(int i = 0; i < times.size(); i++){
            if(cnt >= n)
                break;
            cnt += mid / (long long)times[i];
        }
        
        if(cnt >= n){
            high = mid - 1;
            answer = mid;
        }
        else
            low = mid + 1;
    }
    
    return answer;
}