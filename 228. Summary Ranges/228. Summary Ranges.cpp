#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {

public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int curNum = 0;
        int times = 0;
        int n = nums.size();
        if(!n){
            return res;
        }

        int a;
        int b;

        while(curNum+times<n){
            a = nums[curNum];
            b = nums[curNum+times];
            if(b-a==times){
                times++;
            }
            else if(times==1){
                string str = "\"" + to_string(a) + "\"";
                res.push_back(str);
                curNum += times;
                times = 0;
            }
            else{
                string str = "\"" + to_string(a) + "->" + to_string(a+times-1) + "\"";
                res.push_back(str);
                curNum += times;
                times = 0;
            }
        }

        if(!times){
            return res;
        }
        else if(times==1){
            a = nums[curNum];
            string str = "\"" + to_string(a) + "\"";
            res.push_back(str);
        }
        else{
            a = nums[curNum];
            string str = "\"" + to_string(a) + "->" + to_string(a+times-1) + "\"";
            res.push_back(str);
        }

        return res;
    }
};


int main(){
    vector<int> nums = {0,2,3,4,6,8,9};
    Solution sol;
    vector<string> res = sol.summaryRanges(nums);
    int n = res.size();
    for(int i = 0;i < n;i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
