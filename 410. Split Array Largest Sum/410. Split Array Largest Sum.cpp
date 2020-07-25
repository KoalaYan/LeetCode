#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
    long long low;
    long long high;
public:
    bool satis(long long limit, vector<int>& nums, int m){
        int i = 0;
        long long lim = limit;
        while(m != 0 && i != n){
            //cout<<m<<' '<<lim<<endl;
            if(lim >= nums[i]){
                lim -= nums[i];
                i++;
            }
            else{
                m--;
                lim = limit;
            }
        }
        if(m==0){
            //cout<<"no\n";
            return false;
        }
        else
            return true;
    }

    int minMax(long long low, long long high, vector<int>& nums, int m){
        cout<<low<<' '<<high<<endl;
        if(low == high)
            return low;

        int mid = low + (high - low) / 2;
        if(satis(mid,nums,m)){
            //cout<<"yes\n";
            return minMax(low, mid, nums, m);
        }
        else{
            return minMax(mid+1, high, nums, m);
        }
    }

    int splitArray(vector<int>& nums, int m){
        n = nums.size();
        low = high = nums[0];
        for(int i = 1;i < n;i++){
            high += nums[i];
            if(low<nums[i]){
                low = nums[i];
            }
        }
        //cout<<"low:"<<low<<" high:"<<high<<endl;
        return minMax(low, high, nums, m);
    }
};

int main(){
    vector<int> nums = {1,2147483647};
    int m = 2;
    Solution sol;
    int res = sol.splitArray(nums, m);
    cout<<res;
    return 0;
}
