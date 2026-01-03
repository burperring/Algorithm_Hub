#include <string>
#include <set>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> CreateTwoCharSet(const string& str) 
{
    vector<string> two_char_grams;
    for (size_t i = 0; i + 1 < str.length(); ++i) 
    {
        string sub = str.substr(i, 2);
        
        // 알파벳만 남기고 나머지 제거
        sub.erase(remove_if(sub.begin(), sub.end(), [](char c){
            return !isalnum(c) || isdigit(c);
        }), sub.end());
        
        if(sub.length() == 2)
            two_char_grams.push_back(sub);
    }
    
    return two_char_grams;
}

void ChangeStr(string& str)
{
    // 알파벳을 소문자로 변경
    transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return tolower(c); });
}

int solution(string str1, string str2) {
    int answer = 0;
    ChangeStr(str1);
    ChangeStr(str2);

    vector<string> ms1 = CreateTwoCharSet(str1);
    vector<string> ms2 = CreateTwoCharSet(str2);
    sort(ms1.begin(), ms1.end());
    sort(ms2.begin(), ms2.end());
    
    if(ms1.size() == 0 && ms2.size() == 0)
        return 65536;
    if(ms1.size() == 0 || ms2.size() == 0)
        return 0;
    
    int i1 = 0;
    int i2 = 0;
    int iCount = 0;
    while(1)
    {
        if(ms1[i1] == ms2[i2])
        {
            iCount++;
            i1++;
            i2++;
        }
        else if(ms1[i1] > ms2[i2])
            i2++;
        else
            i1++;
        
        if(i1 == ms1.size() || i2 == ms2.size())
            break;
    }
    
    float f = (float)iCount / (float)(ms1.size() + ms2.size() - iCount);
    answer = f * 65536;
    
    return answer;
}