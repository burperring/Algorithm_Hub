#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmpA(pair<string, int> a, pair<string, int> b){            // 장르 전체 재생 횟수 정렬
    return a.second > b.second;
}

bool cmpB(pair<int, int> a, pair<int, int> b){                  // 각 장르 별 재생 횟수, 고유번호 정렬
    if(a.first == b.first)                                      // 재생 횟수가 같을 경우
        return a.second < b.second;                             // 고유 번호가 낮은 노래 먼저 정렬
    else
        return a.first > b.first;                               // 재생 횟수가 많은 순서대로 정렬
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> Mcnt;                                      // 장르 전체 재생 횟수
    map<string, vector<pair<int, int>>> MGenres;                // 각 장르 별 재생 횟수, 고유번호
    
    for(int i = 0; i < genres.size(); i++){
        Mcnt[genres[i]] += plays[i];                            // 장르 전체 재생 횟수 대입
        MGenres[genres[i]].push_back({plays[i],i});             // 각 장르 별 재생 횟수, 고유번호 대입
    }
    
    for(auto &i : MGenres){                                     // 장르별 플레이 횟수에 따라 정렬 시도
        sort(i.second.begin(), i.second.end(), cmpB);           
    }
    
    vector<pair<string, int>> Vcnt(Mcnt.begin(), Mcnt.end());   // 정렬을 위해 Map을 Vector로 변환
    sort(Vcnt.begin(), Vcnt.end(), cmpA);
    
    for(auto x : Vcnt){
        for(int i = 0; i < MGenres[x.first].size(); i++){
            answer.push_back(MGenres[x.first][i].second);
            if(i == 1) break;
        }
    }
    
    return answer;
}