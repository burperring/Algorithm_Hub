#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2){
    return s1 + s2 > s2 + s1;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> sNumbers;
    
    for(auto x : numbers){
        sNumbers.push_back(to_string(x));
    }
    
    sort(sNumbers.begin(), sNumbers.end(), comp);
    
    if(sNumbers[0] == "0"){
        answer = "0";
        return answer;
    }
    
    for(int i = 0; i < sNumbers.size(); i++){
        answer += sNumbers[i];
    }
    
    return answer;
}