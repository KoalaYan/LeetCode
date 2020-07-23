#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
    int m;
    int **p;
public:
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        p = new int *[2];
        for(int i = 0;i < 2;i++){
            p[i] = new int [m];
        }
        p[0][0] = grid[0][0];
        for(int j = 1;j < m;j++){
            p[0][j] = p[0][j-1] + grid[0][j];
        }

        for(int i = 1;i < n;i++){
            p[i%2][0] = p[(i-1)%2][0] + grid[i][0];
            //int temp;
            for(int j = 1;j < m;j++){
                p[i%2][j] = min(p[(i-1)%2][j], p[i%2][j-1]) + grid[i][j];
            }
        }
        return p[(n-1)%2][m-1];
    }
};

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution sol;
    cout<<sol.minPathSum(grid);
    return 0;
}
