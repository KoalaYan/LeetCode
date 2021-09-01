#include"vector"
#include"algorithm"
#include"iostream"
#include"stack"
using namespace std;

class Solution {
    vector<string> res;
    int n;
    void dfs(string digits, string pre, int i){
        if(i==n){
            res.push_back(pre);
        }
        if(digits[i]=='2'){
            dfs(digits, pre+'a', i+1);
            dfs(digits, pre+'b', i+1);
            dfs(digits, pre+'c', i+1);
        }
        if(digits[i]=='3'){
            dfs(digits, pre+'d', i+1);
            dfs(digits, pre+'e', i+1);
            dfs(digits, pre+'f', i+1);
        }
        if(digits[i]=='4'){
            dfs(digits, pre+'g', i+1);
            dfs(digits, pre+'h', i+1);
            dfs(digits, pre+'i', i+1);
        }
        if(digits[i]=='5'){
            dfs(digits, pre+'j', i+1);
            dfs(digits, pre+'k', i+1);
            dfs(digits, pre+'l', i+1);
        }
        if(digits[i]=='6'){
            dfs(digits, pre+'m', i+1);
            dfs(digits, pre+'n', i+1);
            dfs(digits, pre+'o', i+1);
        }
        if(digits[i]=='7'){
            dfs(digits, pre+'p', i+1);
            dfs(digits, pre+'q', i+1);
            dfs(digits, pre+'r', i+1);
            dfs(digits, pre+'s', i+1);
        }
        if(digits[i]=='8'){
            dfs(digits, pre+'t', i+1);
            dfs(digits, pre+'u', i+1);
            dfs(digits, pre+'v', i+1);
        }
        if(digits[i]=='9'){
            dfs(digits, pre+'w', i+1);
            dfs(digits, pre+'x', i+1);
            dfs(digits, pre+'y', i+1);
            dfs(digits, pre+'z', i+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        if(!n)
            return res;
        dfs(digits,"",0);
        return res;
    }
};

int main(){
    string digits = "23";
    Solution sol;
    vector<string> res = sol.letterCombinations(digits);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
