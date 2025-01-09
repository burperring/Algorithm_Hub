#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> mFind;
    map<int, string> mSet;
    
    for(int i = 0; i < players.size(); i++){
        mFind.insert({players[i], i});
        mSet.insert({i, players[i]});
    }
    
    for(auto x : callings){
        int rank = mFind[x];
        string player = mSet[rank];
        
        string frontPlayer = mSet[rank - 1];
        
        mFind[player] = rank - 1;
        mSet[rank - 1] = player;
        mFind[frontPlayer] = rank;
        mSet[rank] = frontPlayer;
    }
    
    for(int i = 0; i < players.size(); i++){
        answer.push_back(mSet[i]);
    }
    
    return answer;
}