#include <string>
#include <vector>

using namespace std;

int answer = 0;

bool Check(vector<vector<int>> board, int depth, int i){
    for(int a = 0; a < depth; a++){
        for(int b = 0; b < board.size(); b++){
            if(board[a][b] == 1){
                if(b == i) return false;
                if(abs(a - depth) == abs(i - b)) return false;
            }
        }
    }
    
    return true;
}

void nQueen(vector<vector<int>> board, int n, int depth){
    if(depth == n){
        answer++;
        return;
    }

    for(int i = 0; i < n; i++){
        board[depth][i] = 1;

        if(depth != 0){
            if(Check(board, depth, i)) 
                nQueen(board, n, depth + 1);
        }
        else{
            nQueen(board, n, depth + 1);
        }

        board[depth][i] = 0;
    }
}

int solution(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    nQueen(board, n, 0);
    
    return answer;
}