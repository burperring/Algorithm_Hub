#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> nummap; 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(string s) {
    nummap.insert({ "zero",0 });
    nummap.insert({ "one",1 });
    nummap.insert({ "two",2 });
    nummap.insert({ "three",3 });
    nummap.insert({ "four",4 });
    nummap.insert({ "five",5 });
    nummap.insert({ "six",6 });
    nummap.insert({ "seven",7 });
    nummap.insert({ "eight",8 });
    nummap.insert({ "nine",9 });

    size_t position = 0;

    for(auto iter = nummap.begin(); iter != nummap.end(); ++iter)
    {
        while((position = s.find(iter->first)) != string::npos)
        {
            s.replace(position, iter->first.size(), to_string(iter->second));
        }
    }
    int answer = stoi(s);

    return answer;
}