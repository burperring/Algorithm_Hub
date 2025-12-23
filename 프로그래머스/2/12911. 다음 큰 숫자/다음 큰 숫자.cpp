#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = n + 1;
   
    bitset<32> bs(n);
    int num = bs.count();
    
    while(true)
    {
        bitset<32> bsa(answer);
        int check = bsa.count();
        if(num == check)
            break;
        
        answer++;
    }
    
    return answer;
}