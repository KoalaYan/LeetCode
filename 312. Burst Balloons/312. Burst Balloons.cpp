#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int **p;
    int n;
public:
    void init(vector<int>& nums){
        n = nums.size();
        p = new int *[n];
        for(int i = 0;i < n;i++){
            p[i] = new int[n];
            for(int j = 0;(j <= i+1) && (j<n);j++){
                p[i][j] = 0;
            }
            for(int j = i+2;j < n;j++){
                p[i][j] = -1;
            }
        }
    }
    int val(int x, int y, vector<int>& nums){
        if(p[x][y] == -1){
            p[x][y] = nums[x]*nums[x+1]*nums[y] + val(x+1,y,nums);
            for(int i = x+2; i < y;i++){
                if(p[x][y]<nums[x]*nums[i]*nums[y] + val(x,i,nums) + val(i,y,nums)){
                    p[x][y] = nums[x]*nums[i]*nums[y] + val(x,i,nums) + val(i,y,nums);
                }
            }
        }

        return p[x][y];
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        init(nums);
        //cout<<nums[0]<<' '<<nums[n-1]<<endl;
        return val(0,n-1,nums);
    }
};

int main(){
    vector<int> nums = {3,1,5,8};
    Solution sol;
    int maxcoin = sol.maxCoins(nums);
    cout<<maxcoin;
    return 0;
}
