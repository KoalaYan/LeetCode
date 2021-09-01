#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;
class Solution {
    int n;
    int m;
    char rec;
    bool **vis;
    int xx[4] = {0,1,0,-1};
    int yy[4] = {1,0,-1,0};

    bool dfs(vector<vector<char>>& grid, int x, int y, int prex, int prey){
        //cout<<x<<' '<<y<<endl;
        vis[x][y] = true;
        int nx;
        int ny;
        for(int i = 0;i < 4;i++){
            nx = x+xx[i];
            ny = y+yy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m || (nx==prex&&ny==prey) || grid[nx][ny]!=rec){
                continue;
            }
            if(vis[nx][ny]){
                return true;
            }
            if(dfs(grid, nx, ny, x, y)){
                return true;
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vis = new bool*[n];
        for(int i = 0;i < n;i++){
            vis[i] = new bool [m];
            for(int j = 0;j < m;j++){
                vis[i][j] = false;
            }
        }


        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j]){
                    rec = grid[i][j];
                    if(dfs(grid, i, j, -1, -1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> grid = {{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}};
    Solution sol;
    cout<<sol.containsCycle(grid);
    return 0;
}
