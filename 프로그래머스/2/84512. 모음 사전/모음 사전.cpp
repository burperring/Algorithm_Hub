#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int iNum;

int iWordCount(int num, int index){
    int a = 0;
    
    for(int i = 1; i < index; i++){
        a += pow(5, i);
    }
    
    return a * num;
}

int solution(string word) {
    int answer = 0;
    
    for(int i = 0; i < word.size(); i++){
        switch(word[i]){
            case 'A':
                answer += 1;
                break;
            case 'E':
                iNum = iWordCount(1, 5 - i);
                answer += (2 + iNum);
                break;
            case 'I':
                iNum = iWordCount(2, 5 - i);
                answer += (3 + iNum);
                break;
            case 'O':
                iNum = iWordCount(3, 5 - i);
                answer += (4 + iNum);
                break;
            case 'U':
                iNum = iWordCount(4, 5 - i);
                answer += (5 + iNum);
                break;
        }
    }
    
    return answer;
}