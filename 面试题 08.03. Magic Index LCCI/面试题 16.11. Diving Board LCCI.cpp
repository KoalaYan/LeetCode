#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++)
            if(nums[i]==i)
                return i;
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,2,3,4,5};
    cout<<sol.findMagicIndex(nums);
    return 0;
}
