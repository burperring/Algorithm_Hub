#include <string>
#include <vector>
using namespace std;

int res_max = 0;
vector<int> answer = {-1};

void dfs(int cnt, int n, int idx, vector<int> info, vector<int> tmp){
    if (cnt == n){  //화살을 다 쏘았고
        int res = 0;
        
        for (int i=0; i < 11; i++){
            if (tmp[i] > info[i]) res += (10 - i);
            else if (info[i]) res -= (10 - i);
        }
        
        if (res > res_max && res){                //점수차가 더 크면
            res_max = res;
            answer = tmp;
        }
        else if (res == res_max && res){          //점수차가 같다면
            for (int i = 10; i >= 0; i--){        //가장 낮은 점수를 많이 쏜 경우를 찾는다
                if (answer[i] > tmp[i]) return;
                else if (answer[i] < tmp[i]){
                    answer = tmp;
                    break;
                }
            }
        }
        return ;
    }
    
    for(int i = idx; i <= 10; i++){
        int num = info[i]+1;                //점수를 얻으려면 쏘아야하는 개수
        if (num > n-cnt) num = n - cnt;     //가진 화살수보다 쏴야하는 수가 많다면 가진만큼만 쏜다.
        tmp[i] = num;                       //쏘고
        dfs(cnt + num, n, i + 1, info, tmp);//dfs넘겨줌
        tmp[i] = 0;                         //취소
    }
}

vector<int> solution(int n, vector<int> info){
    vector<int> tmp(11, 0);//라이언이 쏜 기록
    dfs(0, n, 0, info, tmp);
    return answer;
}