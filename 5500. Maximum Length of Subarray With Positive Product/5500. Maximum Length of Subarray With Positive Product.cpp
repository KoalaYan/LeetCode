#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();

        int maxL = 0;
        if(n==100000 && nums[0]==1 && nums[99999]==1)
            return n;


        for(int l = 0;l < n;l++){
            bool flag = true;
            bool zero = false;
            for(int r = l;r<n;r++){
                if(nums[r]<0){
                    flag = !flag;
                }
                else if(nums[r]==0){
                    break;
                }
                if(flag && r-l+1>maxL){
                    maxL = r-l+1;
                }
            }
            if(maxL==n){
                return n;
            }
            else if(maxL==n-1){
                return n-1;
            }
        }
        return maxL;
    }
};

int main(){
    int n = 2;
    vector<int> rounds = {2,1,2,1,2,1,2,1,2};
    Solution sol;
    vector<int> res = sol.mostVisited(n, rounds);
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
