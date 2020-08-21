#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int n;
    int m;
    bool isMine(vector<vector<char>>& board, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        if(board[i][j] == 'M'){
            return true;
        }
        else{
            return false;
        }
    }
    bool ff(int i, int j){
        if(i<0 || j<0 || i>=n || j>=m){
            return true;
        }

        if(flag[i][j])
            return true;
        else
            return false;
    }

    bool **flag;
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size();
        m = board[0].size();
        flag = new bool*[n];
        for(int i = 0;i < n;i++){
            flag[i] = new bool [m];
            for(int j = 0;j < m;j++){
                flag[i][j] = false;
            }
        }
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        queue<vector<int>> que;
        int num;
        que.push(click);
        flag[click[0]][click[1]] = true;
        vector<int> temp;
        int i;
        int j;
        while(!que.empty()){
            temp = que.front();
            que.pop();
            i = temp[0];
            j = temp[1];
            //flag[i][j] = true;
            if(board[i][j]=='M'){
                continue;
            }
            num = isMine(board, i-1,j-1) + isMine(board, i-1,j) + isMine(board, i-1,j+1)
             + isMine(board, i,j-1) + isMine(board, i,j+1) + isMine(board, i+1,j-1) + isMine(board, i+1,j) + isMine(board, i+1,j+1);
            board[i][j] = num + '0';
            if(num==0){
                board[i][j] = 'B';
            }
            else{
                continue;
            }
            if(!ff(i-1, j-1)){
                que.push({i-1,j-1});
                flag[i-1][j-1] = true;
            }
            if(!ff(i-1, j)){
                que.push({i-1,j});
                flag[i-1][j] = true;
            }
            if(!ff(i-1, j+1)){
                que.push({i-1,j+1});
                flag[i-1][j+1] = true;
            }
            if(!ff(i, j-1)){
                que.push({i,j-1});
                flag[i][j-1] = true;
            }
            if(!ff(i, j+1)){
                que.push({i,j+1});
                flag[i][j+1] = true;
            }
            if(!ff(i+1, j-1)){
                que.push({i+1,j-1});
                flag[i+1][j-1] = true;
            }
            if(!ff(i+1, j)){
                que.push({i+1,j});
                flag[i+1][j] = true;
            }
            if(!ff(i+1, j+1)){
                que.push({i+1,j+1});
                flag[i+1][j+1] = true;
            }
        }

        return board;
    }
};

void visit(vector<vector<char>> &board){
    int n = board.size();
    int m = board[0].size();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
}
int main(){
    vector<char> q;
    for(int i = 0;i <50;i++){q.push_back('E');}
    vector<vector<char>> board;
    for(int i = 0;i < 50;i++){board.push_back(q);}
    vector<int> click = {29,2};
    /*
    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
    {'E', 'E', 'E', 'E', 'E'},
    {'E', 'E', 'E', 'E', 'E'},
    {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click = {2,1};
    */
    visit(board);
    Solution sol;
    board = sol.updateBoard(board,click);
    visit(board);
    return 0;
}
