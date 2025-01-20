#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    while(1){
        if(abs(a - b) == 1){
            if(a > b && a % 2 == 0)
                break;
            if(b > a && b % 2 == 0)
                break;
        }
        
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;
    }

    return answer;
}