#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int n;
    int m;
    int maxProductPath(vector<vector<int>>& grid, int x, int y, bool neg){
        cout<<endl;
        if(x==n-1 && y==m-1){
            return grid[x][y];
        }
        else if(x==n-1){
            int temp = grid[x][y];
            for(int i = y+1;i<m;i++){
                temp *= grid[x][i];
            }
            return temp;
        }
        else if(y==m-1){
            int temp = grid[x][y];
            for(int i = x+1;i<m;i++){
                temp *= grid[i][y];
            }
            return temp;
        }
        int temp1;
        bool flag1 = false;
        bool flag2 = false;
        bool sym;
        if(grid[x][y]>0){
            temp1 = maxProductPath(grid,x,y+1,neg);
            sym = neg;
        }
        else if(grid[x][y]<0){
            temp1 = maxProductPath(grid,x,y+1,!neg);
            sym = !neg;
        }
        else{
            temp1 = 0;
            sym = neg;
        }
        if(temp1<=0 && sym){
            flag1 = true;
        }
        if(temp1>=0 && sym){
            flag1 = true;
        }

        int temp2;
        if(grid[x][y]>0){
            temp2 = maxProductPath(grid,x+1,y,neg);
        }
        else if(grid[x][y]<0){
            temp2 = maxProductPath(grid,x+1,y,!neg);
        }
        else{
            temp2 = 0;
        }
        cout<<endl;
        cout<<neg<<' '<<x<<' '<<y+1<<' '<<temp1<<endl;
        cout<<neg<<' '<<x+1<<' '<<y<<' '<<temp2<<endl;
        if(temp2<=0 && sym){
            flag2 = true;
        }
        if(temp2>=0 && sym){
            flag2 = true;
        }

        int res = grid[x][y];
        if(flag1&&flag2){
            res *= abs(temp1) > abs(temp2) ? temp1 : temp2;
        }
        else if(flag1){
            res *= temp1;
        }
        else if(flag2){
            res *= temp2;
        }
        else{
            if(neg){
                return 1;
            }
            else{
                return -1;
            }
        }
        return res;
    }
public:
    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int temp = maxProductPath(grid,0,0,0);
        //cout<<temp;
        if(temp<0){
            return -1;
        }
        else{
            return temp;
        }
    }
};

int main(){
    string s = "ababccc";
    Solution sol;
    cout<<sol.maxUniqueSplit(s);
    return 0;
}
