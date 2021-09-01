#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        int times = 0;
        for(int i = 0;i < n;i++){
            times += __builtin_popcount(nums[i]);
            if(nums[i]>temp)
                temp = nums[i];
        }
        while(temp){
            times++;
            temp /= 2;
        }
        return times-1;
    }
};

int main(){
    vector<int> nums = {1,5};
    Solution sol;
    cout<<sol.minOperations(nums);
    return 0;
}
