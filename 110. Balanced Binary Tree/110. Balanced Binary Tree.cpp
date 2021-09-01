#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    bool flag;
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int hl = height(root->left);
        int hr = height(root->right);
        if(abs(hl-hr)>1){
            flag = false;
        }
        root->val = max(hl, hr) + 1;
        return root->val;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;

        flag = true;

        int x = height(root);

        return flag;
    }
};

int main(){


    Solution sol;
    cout<<sol.sortedListToBST(head);
    return 0;
}
