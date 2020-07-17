#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
public:
    int bisearch(int low, int high, vector<int>& nums, int target){
        if(low==high){
            nums.insert(nums.begin()+low, target);
            return low;
        }
        else{
            int mid = (low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target){
                return bisearch(mid+1, high, nums, target);
            }
            else{
                return  bisearch(low, mid, nums, target);
            }
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return bisearch(0, nums.size(), nums, target);
    }
};

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 2;
    Solution sol;
    cout<<sol.searchInsert(nums, target);
    return 0;
}
