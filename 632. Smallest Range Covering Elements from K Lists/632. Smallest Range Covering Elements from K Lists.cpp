#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int *p;
    int *e;
    int k;
public:
    vector<int> smallestRange(vector<vector<int>>& nums){
        int l = -1e5;
        int r = 1e5;
        k = nums.size();
        p = new int[k];
        e = new int[k];
        int small_idx;
        int small_num;
        int large_num;
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > coll;

        large_num = nums[0][0];
        for(int i = 0;i < k;i++){
            p[i] = 0;
            e[i] = nums[i].size();
            coll.push(pair<int,int>(nums[i][0],i));
            if(nums[i][0]>large_num){
                large_num = nums[i][0];
            }
        }
        while(1){
            small_num = coll.top().first;
            small_idx = coll.top().second;
            coll.pop();
            if((large_num-small_num < r-l) || ((large_num-small_num == r-l)&&small_num<l)){
                l = small_num;
                r = large_num;
            }
            if(++p[small_idx]==e[small_idx]){
                return {l,r};
            }
            coll.push(pair<int,int>(nums[small_idx][p[small_idx]],small_idx));
            if(nums[small_idx][p[small_idx]]>large_num){
                large_num = nums[small_idx][p[small_idx]];
            }
        }
    }
};

int main(){
    vector<vector<int>> nums = {{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
    Solution sol;
    vector<int> res = sol.smallestRange(nums);
    cout<<res[0]<<' '<<res[1];
    return 0;
}
