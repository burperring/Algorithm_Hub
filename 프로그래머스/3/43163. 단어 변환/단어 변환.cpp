#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> v[51];
vector<string> vWords;
vector<int> vi;

void find(int start, int cnt, string target, vector<bool> b){
    if(start != 0 && vWords[start-1] == target){
        vi.push_back(cnt);
    }

    for(int i = 0; i < v[start].size(); i++){
        if(!b[v[start][i]]){
            b[v[start][i]] = true;
            find(v[start][i], cnt + 1, target, b);
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 999999999;
    vector<bool> b(51);
    vWords = words;
    
    int a = find(words.begin(), words.end(), target) - words.begin();
    if(a == words.size())
        return answer = 0;
    
    for(int i = 0; i <= words.size(); i++){
        string check;

        if(i == 0)
            check = begin;
        else
            check = words[i-1];

        for(int j = 0; j < words.size(); j++){
            int dif = 0;
            
            if(check != words[j]){
                for(int x = 0; x < check.size(); x++){
                    if(check[x] != words[j][x])
                        dif++;
                }
                if(dif == 1){
                    v[i].push_back(j+1);
                }
            }
        }
    }
    
    find(0, 0, target, b);
    
    if(vi.size() != 0)
        answer = *min_element(vi.begin(), vi.end());
    
    return answer;
}