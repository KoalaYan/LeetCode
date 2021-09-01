#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
public:
    int bisearch(int low, int high, vector<int>& nums){
        if(low==high){
            return nums[low];
        }
        else{
            int mid = (low+high)/2;
            if(nums[mid]>nums[high]){
                return bisearch(mid+1, high, nums);
            }
            else{
                return bisearch(low, mid, nums);
            }
        }
    }

    int findMin(vector<int>& nums){
        return bisearch(0, nums.size()-1, nums);
    }
};

int main(){
    //vector<int> nums = {3,4,5,1,2};
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution sol;
    cout<<sol.findMin(nums);
    return 0;
}
