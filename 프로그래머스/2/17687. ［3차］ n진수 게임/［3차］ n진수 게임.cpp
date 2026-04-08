#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string convertToBaseN(int num, int n) {
    string result = "";
    if (num == 0) return "0";

    while (num > 0) {
        int rem = num % n;
        
        if (rem < 10)
            result += to_string(rem);
        else
            result += (char)('A' + (rem - 10));
        
        num /= n;
    }

    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int num = 0;
    int iturn = 1;
    
    while(1)
    {
        string sn = convertToBaseN(num, n);
        
        for(int i = 0; i < sn.length(); i++)
        {
            if(iturn == p) answer += sn[i];
            iturn++;
            
            if(iturn > m) iturn = 1;
            if(answer.length() == t) break;
        }
        
        if(answer.length() == t) break;
        num++;
    }
    
    return answer;
}