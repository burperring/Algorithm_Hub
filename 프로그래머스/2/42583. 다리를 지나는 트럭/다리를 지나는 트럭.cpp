#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> tTime;
    
    while(1){
        answer++;
        
        if(weight >= truck_weights[tTime.size()]){
            weight -= truck_weights[tTime.size()];
            tTime.push_back(0);
        }
        
        for(int i = 0; i < tTime.size(); i++){
            tTime[i]++;
        }
        
        if(tTime[0] == bridge_length){
            tTime.erase(tTime.begin());
            weight += truck_weights[0];
            truck_weights.erase(truck_weights.begin());
            
            if(truck_weights.size() == 0)
                return answer + 1;
        }

    }
    
    return answer;
}