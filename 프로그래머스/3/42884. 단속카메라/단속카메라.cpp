#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), comp);

    while(routes.size() != 0){
        int iCamera = routes.front()[1];
        routes.erase(routes.begin());
        answer++;
        
        for(int i = 0; i < routes.size(); i++){
            if(routes[i][0] <= iCamera && iCamera <= routes[i][1]){
                routes.erase(routes.begin() + i);
                i--;
            }
        }
    }
    
    return answer;
}