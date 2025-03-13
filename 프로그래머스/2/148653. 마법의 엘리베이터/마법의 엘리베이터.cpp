#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0){
        int curNum = storey % 10;
        int nextNum = (storey / 10) % 10;
        
        if(curNum > 5 || (curNum == 5 && nextNum >= 5))
            storey += 10 - curNum;
        else
            storey -= curNum;
        
        answer += min(curNum, 10 - curNum);
        storey /= 10;
    }
    
    return answer;
}