#include <string>
#include <vector>
#include <iostream>

using namespace std;

int MoveD(int cap, int dP, vector<int>& deliveries){
    if(dP == -1) return dP;
    
    if(deliveries[dP] == 0){
        return MoveD(cap, dP - 1, deliveries);
    }
    else if(cap >= deliveries[dP]){
        cap -= deliveries[dP];
        deliveries[dP] = 0;
        return MoveD(cap, dP - 1, deliveries);
    }
    else{
        deliveries[dP] -= cap;
        return dP;
    }
}

int MoveP(int cap, int pP, vector<int>& pickups){
    if(pP == -1) return pP;
    
    if(pickups[pP] == 0){
        return MoveP(cap, pP - 1, pickups);
    }
    else if(cap >= pickups[pP]){
        cap -= pickups[pP];
        pickups[pP] = 0;
        return MoveP(cap, pP - 1, pickups);
    }
    else{
        pickups[pP] -= cap;
        return pP;
    }
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int dP = n - 1, pP = n - 1;
    
    while(deliveries[dP] == 0 && dP != -1){
        dP--;
    }
    
    while(pickups[pP] == 0 && pP != -1){
        pP--;
    }

    while(dP != -1 || pP != -1){
        answer += dP > pP ? (dP + 1) * 2 : (pP + 1) * 2;
        
        dP = MoveD(cap, dP, deliveries);
        pP = MoveP(cap, pP, pickups);
    }
    
    return answer;
}