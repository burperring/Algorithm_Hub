#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int cnt;
    long long num;
    long long maxSum = -9223372036854775807;
    long long minSum = 9223372036854775807;
    cin >> cnt;

    vector<char> c = {'+', '-', '*', '/'};
    vector<long long> v;
    vector<char> op;
    for(int i = 0; i < cnt; i++){
        cin >> num;
        v.push_back(num);
    }

    for(int i = 0; i < 4; i++){
        cin >> num;
        for(int j = 0; j < num; j++){
            op.push_back(c[i]);
        }
    }
    sort(op.begin(), op.end());

    do{
        long long sum = v[0];
        for(int i = 0; i < op.size(); i++){
            if(op[i] == '+') sum += v[i + 1];
            else if(op[i] == '-') sum -= v[i + 1];
            else if(op[i] == '*') sum *= v[i + 1];
            else if(op[i] == '/') sum /= v[i + 1];
        }
        maxSum = max(maxSum, sum);
        minSum = min(minSum, sum);
    }while(next_permutation(op.begin(), op.end()));

    cout << maxSum << endl;
    cout << minSum;
}