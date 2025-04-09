#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

void cal(vector<int> vH, vector<int> vA, int sum, int hp, int n){
    if(hp <= 0 || n > vH.size()) return;

    answer = answer > sum ? answer : sum;
    cal(vH, vA, sum, hp, n + 1);
    cal(vH, vA, sum += vA[n], hp -= vH[n], n + 1);
}

int main()
{
    int n;
    cin >> n;

    vector<int> vH(n);
    vector<int> vA(n);

    for(int i = 0; i < n; i++){
        cin >> vH[i];
    }

    for(int i = 0; i < n; i++){
        cin >> vA[i];
    }

    cal(vH, vA, 0, 100, 0);
    cout << answer;
}