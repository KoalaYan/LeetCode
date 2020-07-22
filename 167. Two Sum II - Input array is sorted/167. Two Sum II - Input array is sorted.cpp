#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
public:
    int bisearch(int low, int high, vector<int>& nums, int target){
        if(low>high)
            return -1;

        if(low==high){
            if(nums[low]==target)
                return low;
            else
                return -1;
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

    vector<int> twoSum(vector<int>& numbers, int target) {
        n = numbers.size();
        int rest;
        int plc;
        vector<int> res;
        for(int i = 0;i < n;i++){
            rest = target - numbers[i];
            plc = bisearch(i+1,n-1,numbers,rest);
            if(plc!=-1){
                res.insert(res.end(), i+1);
                res.insert(res.end(), plc+1);
                return res;
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = sol.twoSum(numbers, target);
    cout<<res[0]<<' '<<res[1];
    return 0;
}
