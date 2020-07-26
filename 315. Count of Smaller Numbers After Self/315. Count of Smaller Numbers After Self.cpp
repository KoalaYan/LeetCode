#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
    vector<int> number;
    vector<int> basket;

    int lowbit(int x){
        return x & (-x);
    }
    void change(int x){
        while(x<n){
            basket[x] += 1;
            x += lowbit(x);
        }
        return;
    }
    int sum(int k){
        int res = 0;
        while(k>0){
            res += basket[k];
            k -= lowbit(k);
        }
        return res;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> resList;

        //copy and erase
        number.assign(nums.begin(), nums.end());
        sort(number.begin(),number.end());
        number.erase(unique(number.begin(),number.end()), number.end());
        //initialize basket
        basket.resize(number.size()+5,0);
        n = basket.size();

        int id;
        for(int i = nums.size()-1; i>=0; i--){
            //cout<<i<<endl;
            id = lower_bound(number.begin(), number.end(), nums[i]) - number.begin() + 1;
            //cout<<i<<' '<<id<<endl;
            resList.push_back(sum(id-1));
            change(id);
        }

        reverse(resList.begin(), resList.end());

        return resList;
    }
};

int main(){
    vector<int> nums = {-1};
    Solution sol;
    vector<int> res = sol.countSmaller(nums);
    for(int i = 0;i < res.size();i++)
        cout<<res[i]<<' ';
    //cout<<sol.intersect(nums1, nums2);
    return 0;
}
