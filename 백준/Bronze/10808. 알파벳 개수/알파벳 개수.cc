#include <iostream>

using namespace std;

int main()
{
    int arr[26] = {0};
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        int cnt = s[i] - 97;
        arr[cnt]++;
    }

    for(int i = 0; i < 26; i++){
        cout << arr[i] << " ";
    }
}