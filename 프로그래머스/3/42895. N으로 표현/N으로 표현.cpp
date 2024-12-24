#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;                // 최솟값이 8보다 크면 -1 리턴
    unordered_set<int> dp[8];       // 정렬할 필요 X -> unordered_set 사용(set 보다 빠르다)
                                    // unordered_set : O(1), set : O(logn)
    int sum = 0;
    for(int i = 0; i < 8; i++){
        sum = sum * 10 + N;         // N, NN, NNN, ... 에 해당하는 수 기입
        dp[i].insert(sum);      
    }
    
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < i; j++){
            for(int x : dp[j]){
                for(int y : dp[i-j-1]){
                    dp[i].insert(x+y);
                    dp[i].insert(x-y);
                    dp[i].insert(x*y);
                    if(y != 0)
                        dp[i].insert(x/y);
                }
            }
        }
    }
    
    for(int i = 0; i < 8; i++){
        if(dp[i].find(number) != dp[i].end()){
            answer = i+1;
            break;
        }
    }
    
    return answer;
}