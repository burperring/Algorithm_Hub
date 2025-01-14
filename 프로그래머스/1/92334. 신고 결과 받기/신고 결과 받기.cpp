#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    vector<string> doReport;
    vector<string> getReport;
    unordered_map<string, set<string>> um;
    
    for(auto x : report){
        string buffer;
        istringstream ss1(x);
        vector<string> vSplit;
        
        while(getline(ss1, buffer, ' ')){
            vSplit.push_back(buffer);
        }
        
        doReport.push_back(vSplit[0]);
        getReport.push_back(vSplit[1]);
    }
    
    for(int i = 0; i < doReport.size(); i++){
        um[getReport[i]].insert(doReport[i]);
    }
    
    for(auto x : um){
        if(x.second.size() >= k){
            for(auto iter = x.second.begin(); iter != x.second.end(); iter++){
                int num = find(id_list.begin(), id_list.end(), *iter) - id_list.begin();
                answer[num]++;
            }
        }
    }
    
    return answer;
}