#include"vector"
#include"algorithm"
#include"iostream"
#include"cmath"
#include"unordered_set"
using namespace std;

class Solution {
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& seq, int start){
        if(seq.size()>1){
            res.push_back(seq);
        }
        unordered_set<int> uset;
        for(int i = start;i<nums.size();i++){
            if((seq.empty() || nums[i]>=seq.back()) && uset.find(nums[i])==uset.end()){
                seq.push_back(nums[i]);
                dfs(nums, res, seq, i+1);
                seq.pop_back();
                uset.insert(nums[i]);
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        dfs(nums, res, seq, 0);
        return res;
    }

};

int main(){
    vector<int> nums = {6,6,7};
    Solution sol;
    vector<vector<int>> res = sol.findSubsequences(nums);
    for(int i = 0;i < res.size();i++){
        for(int j = 0;j < res[i].size();j++){
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
