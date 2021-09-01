#include"vector"
#include"algorithm"
#include"iostream"
#include"stack"
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        int n = s.length();
        int i = 0;
        while(i<n){
            if(s[i]=='[' || s[i]=='(' || s[i]=='{'){
                stk.push(s[i]);
                i++;
            }
            else{
                if(s[i]!=stk.top()){
                    return false;
                }
                else{
                    stk.pop();
                    i++;
                }
            }
        }
        if(stk.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    vector<int> nums = {1,3,5,6};
    int target = 2;
    Solution sol;
    cout<<sol.searchInsert(nums, target);
    return 0;
}
