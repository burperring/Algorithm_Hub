#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m = {{'R', 0}, {'T', 0},
                        {'C', 0}, {'F', 0},
                        {'J', 0}, {'M', 0},
                        {'A', 0}, {'N', 0}};
    
    for(int i = 0; i < survey.size(); i++){
        switch(choices[i]){
            case 1:
                m[survey[i][0]] += 3;
                break;
            case 2:
                m[survey[i][0]] += 2;
                break;
            case 3:
                m[survey[i][0]] += 1;
                break;
            case 4:
                break;
            case 5:
                m[survey[i][1]] += 1;
                break;
            case 6:
                m[survey[i][1]] += 2;
                break;
            case 7:
                m[survey[i][1]] += 3;
                break;
        }
    }
    
    answer += m['R'] >= m['T'] ? 'R' : 'T';
    answer += m['C'] >= m['F'] ? 'C' : 'F';
    answer += m['J'] >= m['M'] ? 'J' : 'M';
    answer += m['A'] >= m['N'] ? 'A' : 'N';
    
    return answer;
}