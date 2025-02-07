#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(long long int n){
    for(long long int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<int> v;
    vector<long long int> vcheck;
    
    while(n != 0){
        int num = n % k;
        v.push_back(num);
        n /= k;
    }
    reverse(v.begin(), v.end());
    v.push_back(0);
    
    long long int p = 0;
    for(auto x : v){
        if(x == 0 && p != 0){
            vcheck.push_back(p);
            p = 0;
        }
        else{
            p *= 10;
            p += x;
        }
    }
    
    for(auto x : vcheck){
        if(x == 1) continue;
        if(isPrime(x))
            answer++;
    }
    
    return answer;
}