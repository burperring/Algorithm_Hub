#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iostream>

using namespace std;

int min(string time){
    string h, m;
    h += time[0];
    h += time[1];
    m += time[3];
    m += time[4];
    
    int ih = stoi(h);
    int im = stoi(m);
    
    return ih * 60 + im;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> mFee;
    unordered_map<string, int> umTime;
    
    for(auto x : records){
        vector<string> v;
        stringstream ss(x);
        string str_buf;
        while(ss >> str_buf){
            v.push_back(str_buf);
        }
        
        if(v[2] == "IN"){
            int m = min(v[0]);
            umTime[v[1]] = m;
        }
        else{
            int in = umTime[v[1]];
            int out = min(v[0]);
            mFee[v[1]] += (out - in);
            umTime.erase(v[1]);
        }
    }
    
    if(!umTime.empty()){
        for(auto x : umTime){
            int in = x.second;
            int out = min("23:59");
            mFee[x.first] += (out - in);
        }
    }
    
    for(auto x : mFee){
        if(x.second <= fees[0])
            answer.push_back(fees[1]);
        else{
            int result = (x.second - fees[0] - 1) / fees[2] + 1;
            int fee = fees[1] + result * fees[3];
            answer.push_back(fee);
        }
    }
    
    return answer;
}