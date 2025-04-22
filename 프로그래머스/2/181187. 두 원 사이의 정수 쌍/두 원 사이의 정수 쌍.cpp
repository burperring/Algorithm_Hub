#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long a1 = 0, a2 = 0;
    
    for(int i = 1; i <= r2; i++){
        long long num = pow(r2, 2) - pow(i, 2);
        num = sqrt(num);
        a2 += (num * 2) + 1;
    }
    a2 *= 2;
    a2 += (r2 * 2) + 1;
    
    for(int i = 1; i < r1; i++){
        double check = pow(r1, 2) - pow(i, 2);
        check = sqrt(check);
        if(check - (int)check == 0)
            check -= 1;
        a1 += ((int)check * 2) + 1;
    }
    a1 *= 2;
    a1 += ((r1 - 1) * 2) + 1;

    answer = a2 - a1;
    
    return answer;
}