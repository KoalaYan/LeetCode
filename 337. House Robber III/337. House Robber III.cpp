#include"vector"
#include"algorithm"
#include"iostream"
#include"unordered_map"
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode*l, TreeNode*r) : val(x), left(l), right(r) {}
};

class Solution {
    unordered_map <TreeNode*, int> f, g;

    void dfs(TreeNode* root){
        if(!root)
            return;
        dfs(root->left);
        dfs(root->right);

        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left],g[root->left]) + max(f[root->right],g[root->right]);
    }
public:
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root],g[root]);
    }
};

int main(){
    TreeNode*l = new TreeNode(1);
    TreeNode*r = new TreeNode(3);
    l = new TreeNode(4,l,r);
    r = new TreeNode(1);
    r = new TreeNode(5,NULL,r);
    TreeNode* root = new TreeNode(3,l,r);
    Solution sol;
    cout<<sol.rob(root);
    return 0;
}
