#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    
    while(s != "1"){
        int iNextLength = 0;
        string tmp = "";
        
        answer[0]++;
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0')
                answer[1]++;
            else
                iNextLength++;
        }
        
        for(int i = 1 ; iNextLength >= 1 ; i *= 10){
		    tmp += to_string(iNextLength % 2);
		    iNextLength /= 2;
	    }
        
        s = tmp;
    }
    
    return answer;
}