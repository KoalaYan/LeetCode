#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;


class Solution {
    int mod = 1e9+7;
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();
        int i = n-1;
        int j = m-1;
        long long s1 = 0;
        long long s2 = 0;
        while(i>=0 && j>=0){
            if(nums1[i] > nums2[j]){
                s1 += nums1[i];
                //s1 %= mod;
                i--;
            }
            else if(nums1[i] < nums2[j]){
                s2 += nums2[j];
                //s2 %= mod;
                j--;
            }
            else{
                s1 = max(s1, s2) + nums1[i];
                //s1 %= mod;
                s2 = s1;
                i--;
                j--;
            }
        }
        while(i>=0){
            s1+=nums1[i];
            //s1 %= mod;
            i--;
        }
        while(j>=0){
            s2+=nums2[j];
            //s2 %= mod;
            j--;
        }
        return (max(s1,s2) % mod);
    }
};

int main(){
    vector<int> nums1 = {2,4,5,8,10};
    vector<int> nums2 = {4,6,8,9};
    Solution sol;
    cout<<sol.maxSum(nums1,nums2);
    return 0;
}
