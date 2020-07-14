#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int i = 0;
        int k = nums.size() - 1;
        vector<int> res(nums.size());
        for(;k>=0;k--){
            for(i = 0;i < k;i++){
                if(nums[i]>nums[k]){
                    res[i]++;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {5,2,6,1};
    Solution sol;
    nums = sol.countSmaller(nums);
    for(int i = 0;i < nums.size();i++)
        cout<<nums[i]<<' ';
    //cout<<sol.intersect(nums1, nums2);
    return 0;
}
