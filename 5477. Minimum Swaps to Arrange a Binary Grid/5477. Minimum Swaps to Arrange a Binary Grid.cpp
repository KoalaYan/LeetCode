#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int n;
public:
    int minSwaps(vector<vector<int>>& grid){
        n = grid.size();
        vector<int> zero;
        vector<int> flag;
        for(int i = 0;i < n;i++){
            int j = n-1;
            int num = 0;
            while(j>=0 && grid[i][j]==0){
                num++;
                j--;
            }
            zero.push_back(num);
            flag.push_back(num);
        }
        sort(flag.begin(),flag.end());

        for(int i = 0;i < n;i++){
            if(flag[i]<i)
                return -1;
        }
        int temp;
        int times = 0;
        for(int i = 0;i < n-1;i++){
            int res = -1;
            if(zero[i]<n-i-1){
                for(int j = i+1;j < n;j++){
                    if(zero[j]>=n-i-1){
                        res = j;
                        break;
                    }
                }
                for(int j = res;j > i;j--){
                    temp = zero[j-1];
                    zero[j-1] = zero[j];
                    zero[j] = temp;
                    times++;
                }
            }
        }
        return times;
    }
};

int main(){
    vector<vector<int>> grid = {{1,0,0,0,0,0},{0,0,0,1,0,0},{0,0,0,1,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,0,0,1}};
    //vector<vector<int>> grid = {{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};
    //vector<vector<int>> grid = {{0,0},{0,1}};
    Solution sol;
    cout<<sol.minSwaps(grid);
    return 0;
}
