/*#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> vPrime;
    
    sort(numbers.begin(), numbers.end(), greater<int>());
    int iNum = stoi(numbers);
    
    for(int i = 2; i <= iNum; i++){
        if(isPrime(i))
            vPrime.push_back(i);
    }
    
    for(auto x : vPrime){
        string sCheck = to_string(x);
        string sNum = numbers;
        
        for(int i = 0; i < sCheck.size(); i++){
            for(int j = 0; j < sNum.size(); j++){
                if(sCheck[i] == sNum[j]){
                    sCheck.erase(i,1);
                    sNum.erase(j,1);
                    i--;
                }
            }
        }
        
        if(sCheck == "")
            answer++;
    }
    
    return answer;
}
*/
 //unordered_set, 순열을 이용해서 문제 풀기
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if(n==0 || n==1) return false;
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    unordered_set<int> uos;
    int x = 0;

    sort(numbers.begin(), numbers.end());
    do {
    	for(int i=1; i<numbers.size()+1; i++){
            x = stoi(numbers.substr(0, i));
            if(isPrime(x)) uos.insert(x);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return uos.size();
}
