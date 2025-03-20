#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Score(vector<vector<int>>& v, vector<int> team){
    int sum = 0;

    for(int i = 0; i < team.size(); i++){
        for(int j = 0; j < team.size(); j++){
            sum += v[team[i]][team[j]];
        }
    }

    return sum;
}

int main(){
    int size, num;
    int teamA, teamB, minDif = 99999999;
    cin >> size;
    
    vector<vector<int>> v(size, vector<int>(size, 0));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cin >> num;
            v[i][j] = num;
        }
    }

    vector<bool> vb(size / 2, false);
    vb.insert(vb.end(), size / 2, true);
    do{
        vector<int> t1, t2;
        for(int i = 0; i < size; i++){
            if(vb[i]) t1.push_back(i);
            else t2.push_back(i);
        }

        teamA = Score(v, t1);
        teamB = Score(v, t2);
        minDif = min(minDif, abs(teamA - teamB));

    }while(next_permutation(vb.begin(), vb.end()));

    cout << minDif;
}