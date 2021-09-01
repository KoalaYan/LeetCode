#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
    int m;
    int **p;
public:
    int init(vector<vector<int>>& dungeon){
        n = dungeon.size();
        m = dungeon[0].size();
        //cout<<"n:"<<n<<endl;
        //cout<<"m:"<<m<<endl;
        p = new int*[n];
        for(int i = 0;i < n;i++){
            p[i] = new int[m];
            for(int j = 0;j < m;j++){
                p[i][j] = -1;
            }
        }
        p[n-1][m-1] = 0;
        for(int i = n-2;i >= 0;i--){
            p[i][m-1] = p[i+1][m-1] - dungeon[i+1][m-1];
            if(p[i][m-1]<0)
                p[i][m-1] = 0;
        }
        for(int j = m-2;j >= 0;j--){
            p[n-1][j] = p[n-1][j+1] - dungeon[n-1][j+1];
            if(p[n-1][j]<0)
                p[n-1][j] = 0;
        }
    }
    int opt(int x, int y, vector<vector<int>>& dungeon){
        int temp1, temp2;
        if(p[x][y]==-1){
            temp1 = opt(x+1,y,dungeon) - dungeon[x+1][y];
            temp2 = opt(x,y+1,dungeon) - dungeon[x][y+1];
            if(temp1<0)
                temp1 = 0;
            if(temp2<0)
                temp2 = 0;
            if(temp1<temp2)
                p[x][y] = temp1;
            else
                p[x][y] = temp2;
            //cout<<x<<','<<y<<'='<<p[x][y]<<endl;
        }
        return p[x][y];
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        init(dungeon);
        int res = opt(0,0,dungeon);
        res -= dungeon[0][0];
        if(res<0)
            res = 0;
        return res + 1;
    }
};

int main(){
    vector<vector<int>> dungeon(3, vector<int>(3));
    Solution sol;
    dungeon[0][0] = -2;
    dungeon[0][1] = -3;
    dungeon[0][2] = 3;
    dungeon[1][0] = -5;
    dungeon[1][1] = -10;
    dungeon[1][2] = 1;
    dungeon[2][0] = 10;
    dungeon[2][1] = 30;
    dungeon[2][2] = -5;
    cout<<sol.calculateMinimumHP(dungeon);
    return 0;
}
