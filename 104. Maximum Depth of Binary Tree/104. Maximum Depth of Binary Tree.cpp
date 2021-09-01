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
    TreeNode(int x, TreeNode*l, TreeNode*r) : val(x), left(l), right(r) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> que;
        queue<int> num;
        que.push(root);
        num.push(0);
        TreeNode* p;
        int n = 0;
        while(!que.empty()){
            p = que.front();
            que.pop();
            n = num.front();
            num.pop();
            if(p->left){
                que.push(p->left);
                num.push(n+1);
            }
            if(p->right){
                que.push(p->right);
                num.push(n+1);
            }
        }
        return n+1;
    }
};


int main(){
    TreeNode*l = new TreeNode(15);
    TreeNode*r = new TreeNode(7);
    r = new TreeNode(20,l,r);
    l = new TreeNode(9);

    TreeNode*root = new TreeNode(3, l, r);

    Solution sol;
    cout<<sol.maxDepth(root);
    return 0;
}
