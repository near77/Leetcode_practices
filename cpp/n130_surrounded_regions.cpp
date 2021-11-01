#include <vector>
using std::vector;

class Solution {
// Extend from boarder and perform dfs on each 'O' cell
// Labeled traversed 'O' as 'T'
// Finally traverse all cell, if it's 'O' means that it does not 
// attached to the boarder so label the cell as 'X'. If it's 'T'
// means that it is attached to the boarder so label the cell as
// 'O'
public:
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        int w = board[0].size();
        for(int i = 0; i < h; i++){
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][w-1] == 'O'){
                dfs(board, i, w-1);
            }
        }
        for(int i = 0; i < w; i++){
            if(board[0][i] == 'O'){
                dfs(board, 0, i);
            }
            if(board[h-1][i] == 'O'){
                dfs(board, h-1, i);
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y) {
        int h = board.size();
        int w = board[0].size();
        board[x][y] = 'T';
        if(x == 0){
            if(x + 1 < h){
                if(board[x+1][y] == 'O'){
                    dfs(board, x+1, y);
                }
            }
        }else if(x == h-1){
            if(x-1 > -1){
                if(board[x-1][y] == 'O'){
                    dfs(board, x-1, y);
                }
            }
        }else{
            if(x + 1 < h){
                if(board[x+1][y] == 'O'){
                    dfs(board, x+1, y);
                }
            }
            if(x-1 > -1){
                if(board[x-1][y] == 'O'){
                    dfs(board, x-1, y);
                }
            }
        }
        if(y == 0){
            if(y + 1 < w){
                if(board[x][y+1] == 'O'){
                    dfs(board, x, y+1);
                }
            }
        }else if(y == w-1){
            if(y - 1 > -1){
                if(board[x][y-1] == 'O'){
                    dfs(board, x, y-1);
                }
            }
        }else{
            if(y + 1 < w){
                if(board[x][y+1] == 'O'){
                    dfs(board, x, y+1);
                }
            }
            if(y - 1 > -1){
                if(board[x][y-1] == 'O'){
                    dfs(board, x, y-1);
                }
            }
        }
    }
};

// TLE
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        int w = board[0].size();
        for(int i = 0; i < h; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'T';
            }
            if(board[i][w-1] == 'O'){
                board[i][w-1] == 'T';
            }
        }
        for(int i = 0; i < h; i++){
            if(board[0][i] == 'O'){
                board[0][i] = 'T';
            }
            if(board[h-1][i] == 'O'){
                board[h-1][i] == 'T';
            }
        }
        bool unchanged = false;
        while(!unchanged){
            unchanged = false;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(board[i][j] == 'O'){
                        if(i == 0 || i == h-1 || j == 0 || j == w-1){
                            continue;
                        }else{
                            if(board[i+1][j]=='T' || board[i-1][j]=='T' || board[i][j+1]=='T' || board[i][j-1]=='T'){
                                board[i][j] = 'T';
                                unchanged = true;
                            }
                        }
                    }
                }
            }
        }
        
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};


//Recur->Stack Overflow
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int h = board.size();
        int w = board[0].size();
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == 'O'){
                    if(i == 0 || i == h-1 || j == 0 || j == w-1){
                        dfs(board, i, j, true);
                    }else{
                        dfs(board, i, j, false);
                    }
                }
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    //should be x or not
    void dfs(vector<vector<char>>& board, int x, int y, bool attach_boarder) {
        int h = board.size();
        int w = board[0].size(); 
        if(x == 0){
            if(board[x+1][y] == 'O'){
                dfs(board, x+1, y, attach_boarder);
            }
        }else if(x == h-1){
            if(board[x-1][y] == 'O'){
                dfs(board, x-1, y, attach_boarder);
            }
        }else{
            if(board[x+1][y] == 'O'){
                dfs(board, x+1, y, attach_boarder);
            }
            if(board[x-1][y] == 'O'){
                dfs(board, x-1, y, attach_boarder);
            }
        }
        if(y == 0){
            if(board[x][y+1] == 'O'){
                dfs(board, x, y+1, attach_boarder);
            }
        }else if(y == w-1){
            if(board[x][y-1] == 'O'){
                dfs(board, x, y-1, attach_boarder);
            }
        }else{
            if(board[x][y+1] == 'O'){
                dfs(board, x, y+1, attach_boarder);
            }
            if(board[x][y-1] == 'O'){
                dfs(board, x, y-1, attach_boarder);
            }
        }
        if(attach_boarder){
            board[x][y] = 'T';
        }else{
            bool X = true;
            if(x == 0 || x == h-1){
                X = false;
            }else{
                if(board[x+1][y] == 'T'){
                    X = false;
                }
                if(board[x-1][y] == 'T'){
                    X = false;
                }
            }
            if(y == 0 || y == w-1){
                X = false;
            }else{
                if(board[x][y+1] == 'T'){
                    X = false;
                }
                if(board[x][y-1] == 'T'){
                    X = false;
                }
            }
            if(X){
                board[x][y] = 'X';
            }else{
                board[x][y] = 'T';
            }
        }
    }
};


