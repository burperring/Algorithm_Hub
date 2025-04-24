#include <string>
#include <vector>

using namespace std;

bool playerWin(vector<string> board, char player){
    for(int i = 0; i < 3; i++){
        if(board[i][0] == player && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if(board[0][i] == player && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    
    if(board[0][0] == player && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if(board[0][2] == player && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    
    return false;
}

int solution(vector<string> board) {
    int answer = 1;
    int xCnt = 0, oCnt = 0;
    
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].length(); j++){
            if(board[i][j] == 'O') oCnt++;
            else if(board[i][j] == 'X') xCnt++;
        }
    }
    
    if(xCnt > oCnt || oCnt - xCnt > 1) answer = 0;
    if(playerWin(board, 'O') && oCnt - xCnt != 1) answer = 0;
    if(playerWin(board, 'X') && oCnt - xCnt != 0) answer = 0;
    if(playerWin(board, 'X') && playerWin(board, 'O')) answer = 0;
    
    return answer;
}