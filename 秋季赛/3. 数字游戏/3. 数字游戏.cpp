#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
#include"math.h"
using namespace std;

class Solution {
    int n;
    long long *p;
public:
    vector<int> numsGame(vector<int>& nums) {
        n = nums.size();

        vector<int> res;
        if(!n){
            return res;
        }
        //p[i] means sum of value of abs y = x + nums[i] - i
        p = new long long [n];
        for(int i = 0;i<n;i++){
            p[i] = 0;
        }


        for(int i = 0;i<n;i++){
            res.push_back(0);
        }

        long long min;
        for(int i = 0;i<n;i++){
            min = 1000000006;
            for(int j = 0;j<i;j++){
                p[j] += abs(nums[j] + i - j - nums[i]);
                p[i] += abs(nums[j] + i - j - nums[i]);
                if(p[j]<min){
                    min = p[j];
                }
                //cout<<j<<' '<<p[j]<<endl;
            }

            res[i] = min % 1000000007;
        }
        res[0] = 0;
        return res;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,3,4};
    Solution sol;
    vector<int> res = sol.numsGame(nums);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
