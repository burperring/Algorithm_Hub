#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int iX = 0;
    int iY = 0;
    
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());
    
    while(iX < X.length() && iY < Y.length()){
        if(X[iX] == Y[iY]){
            answer += X[iX];
            iX++;
            iY++;
        }
        else if(X[iX] > Y[iY]){
            iX++;
        }
        else{
            iY++;
        }
    }
    
    if(answer.empty())
        answer = "-1";
    else if(answer[0] == '0')
        answer = "0";
    
    return answer;
}