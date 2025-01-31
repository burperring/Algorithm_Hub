#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int size = 0, eleSize = elements.size();
    set<int> s;
    
    while(size != eleSize){
        size++;
        
        for(int i = 0; i < eleSize; i++){
            int num = 0;
            for(int j = i; j < i + size; j++){
                if(j >= eleSize)
                    num += elements[j - eleSize];
                else
                    num += elements[j];
            }
            s.insert(num);
        }
    }
    
    answer = s.size();
    
    return answer;
}