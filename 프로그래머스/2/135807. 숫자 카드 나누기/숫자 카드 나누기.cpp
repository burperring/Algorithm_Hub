#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

vector<int> factor(int a){
    vector<int> v;
    
    for(int i = 2; i <= a / 2; i++){
        if(a % i == 0) v.push_back(i);
    }
    v.push_back(a);
    
    return v;
}

int ResultNum(vector<int> array, vector<int> factor){
    sort(factor.begin(), factor.end(), greater<int>());
    
    for(auto x : factor){
        bool check = false;
        for(auto it : array){
            if(it % x == 0){
                check = true;
                break;
            }
        }
        if(!check) return x;
    }
    
    return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int numA = arrayA[0];
    int numB = arrayB[0];
    
    for(int i = 1; i < arrayA.size(); i++){
        numA = gcd(numA, arrayA[i]);
        numB = gcd(numB, arrayB[i]);
    }
    
    vector<int> factorA = factor(numA);
    vector<int> factorB = factor(numB);
    
    int resultA = ResultNum(arrayA, factorB);
    int resultB = ResultNum(arrayB, factorA);
    
    answer = max(resultA, resultB);
    
    return answer;
}