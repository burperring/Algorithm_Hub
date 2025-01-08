#include <string>
#include <vector>
#include <iostream>

using namespace std;

string privaciesDay(string privacies, vector<string> terms){
    string returnPriv = privacies.substr(0, 10);
    
    int pMon = stoi(privacies.substr(5, 2));
    int tMon;
    
    for(auto x : terms){
        if(privacies[11] == x[0]){
            tMon = stoi(x.substr(2));
            break;
        }
    }
    
    pMon += tMon;
    
    if(pMon > 12){
        returnPriv[3] += pMon / 12;
        pMon = pMon % 12;
    }
    
    if(returnPriv[8] == '0' && returnPriv[9] == '1'){
        pMon--;
        returnPriv[8] = '2';
        returnPriv[9] = '8';
    }
    else if(returnPriv[9] == '0'){
        returnPriv[8] -= 1;
        returnPriv[9] = '9';
    }
    else
        returnPriv[9] -= 1;
    
    if(pMon > 9)
        returnPriv.replace(5, 2, to_string(pMon));
    else if(pMon == 0){
        returnPriv[3] -= 1;
        returnPriv.replace(5, 2, "12");
    }
    else{
        returnPriv[5] = '0';
        returnPriv.replace(6, 1, to_string(pMon));
    }
    
    if(returnPriv[3] > '9'){
        returnPriv[2] += 1 ;
        returnPriv[3] -= 10;
    }
    else if(returnPriv[3] < '0'){
        returnPriv[2] -= 1;
        returnPriv[3] += 10;
    }
    
    cout << returnPriv << endl;
    
    return returnPriv;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i = 0; i < privacies.size(); i++){
        if(today > privaciesDay(privacies[i], terms)){
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}