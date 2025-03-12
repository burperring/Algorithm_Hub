#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(int i = 0; i <= d; i += k){
        long long dPow = pow(d, 2);
        long long iPow = pow(i, 2);
        long long num = sqrt(dPow - iPow);
        answer += (num / k) + 1;
    }
    
    return answer;
}