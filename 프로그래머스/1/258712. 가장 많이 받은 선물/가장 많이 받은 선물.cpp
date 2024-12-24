/*
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int cnt = 0;
    vector<int> dif(friends.size(), 0);
    vector<int> next(friends.size(), 0);
    vector<vector<int>> v(friends.size(), vector<int>(friends.size() + 1, 0));
    
    sort(friends.begin(), friends.end());
    sort(gifts.begin(), gifts.end());
    
    for(int i = 0; i < friends.size(); i++){
        while(friends[i] == gifts[cnt].substr(0, friends[i].length())){
            string getGift = gifts[cnt].substr(friends[i].length() + 1);
            int check = find(friends.begin(), friends.end(), getGift) - friends.begin();
            v[i][check]++;
            cnt++;
            
            if(cnt == gifts.size())
                break;
        }
        if(cnt == gifts.size())
            break;
    }
    
    for(int i = 0; i < friends.size(); i++){
        int give = 0;
        int get = 0;
        for(int j = 0; j < friends.size(); j++){
            give += v[i][j];
            get += v[j][i];
        }
        dif[i] = give - get;
    }
    
    for(int i = 0; i < friends.size(); i++){
        for(int j = 0; j < friends.size(); j++){
            if(i == j)
                continue;
            if(v[i][j] == v[j][i]){
                if(dif[i] > dif[j])
                    next[i]++;
            }
            else if(v[i][j] > v[j][i])
                next[i]++;
        }
    }
    
    answer = *max_element(next.begin(), next.end());

    return answer;
}*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string,int> names;
int BOARD[51][51];
int people[51];

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    for(int i =0; i < friends.size(); i++){
        string name = friends[i];
        names[name] = i;        
    }
    
    for(int i =0;i<gifts.size(); i++){
        string tg = gifts[i];
        int find_space = tg.find(' ');
        string from_friend = tg.substr(0, find_space);
        string to_friend = tg.substr(find_space+1);
        
        int fIdx = names[from_friend];
        int tIdx = names[to_friend];
        BOARD[fIdx][tIdx]++;
        people[fIdx]++;
        people[tIdx]--;
    }
    
    
    for(int i = 0; i < friends.size(); i++){
        int ret = 0;
        int maxGift = -1;
        int y,x;
        for(int j = 0; j < friends.size(); j++){
            if(i==j)
                continue;
            if(BOARD[i][j] > BOARD[j][i])
                ret++;
            if(BOARD[i][j] == BOARD[j][i]){
                if(people[i] > people[j])
                    ret++;
            }
        }
        answer = max(answer, ret);
    }
    return answer;
}