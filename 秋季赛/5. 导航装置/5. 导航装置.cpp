#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
#include"math.h"
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int n;
    void dfs(TreeNode* root){
        if(root->left){
            dfs(root->left);

        }
        if(root->right){
            dfs(root->right);
        }
        if(!root->left && !root->right){
            n++;
        }

    }
public:
    int navigation(TreeNode* root) {
        n=0;
        dfs(root);
        if(!root->left || !root->right){
            n++;
        }
        return n-1;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,3,4};
    Solution sol;
    vector<int> res = sol.numsGame(nums);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
