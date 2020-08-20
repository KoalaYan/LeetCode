#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
    int m;
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O'){
            return;
        }
        board[i][j] = 'A';
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(!n)
            return;
        m = board[0].size();

        for(int i = 0;i < n;i++){
            dfs(board,i,0);
            dfs(board,i,m-1);
        }
        for(int j = 0;j < m;j++){
            dfs(board,0,j);
            dfs(board,n-1,j);
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                if(board[i][j]=='A'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main(){
    vector<vector<char>> board = {{'O','O','O','O','X','X'},{'O','O','O','O','O','O'},{'O','X','O','X','O','O'},{'O','X','O','O','X','O'},{'O','X','O','X','O','O'},{'O','X','O','O','O','O'}};
    int n = board.size();
    int m = board[0].size();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    Solution sol;
    sol.solve(board);

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
