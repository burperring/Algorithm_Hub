#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    string buff;
    istringstream iss(s);
    vector<int> v;
    
    while(getline(iss, buff, ' ')){
        v.push_back(stoi(buff));
    }
    
    sort(v.begin(), v.end());
    
    answer = to_string(v.front()) + " " + to_string(v.back());

    return answer;
}