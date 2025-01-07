#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int startX = 51, startY = 51;
    int endX = -1, endY = -1;
    
    for(int i = 0; i < wallpaper.size(); i++){
        for(int j = 0; j < wallpaper[i].length(); j++){
            if(wallpaper[i][j] == '#'){
                if(i < startY)
                startY = i;
                if(j < startX)
                    startX = j;
                if(i + 1 > endY)
                    endY = i + 1;
                if(j + 1 > endX)
                    endX = j + 1;
            }
        }
    }
    
    answer.push_back(startY);
    answer.push_back(startX);
    answer.push_back(endY);
    answer.push_back(endX);
    
    return answer;
}