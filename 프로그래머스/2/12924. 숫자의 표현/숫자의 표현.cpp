#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int start = 1;
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        sum += i;
        
        if(sum == n)
            answer++;
        else if(sum > n)
        {
            sum -= (i + start);
            i--;
            start++;
        }
    }
    
    return answer;
}