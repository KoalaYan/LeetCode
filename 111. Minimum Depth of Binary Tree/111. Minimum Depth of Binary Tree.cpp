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
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode*> que[2];
        int dep = 0;
        que[dep%2].push(root);
        TreeNode* temp;
        while(!que[dep%2].empty()){
            temp = que[dep%2].front();
            que[dep%2].pop();
            if(temp->left){
                que[(dep+1)%2].push(temp->left);
            }
            if(temp->right){
                que[(dep+1)%2].push(temp->right);
            }
            if(!temp->left && !temp->right){
                break;
            }
            if(que[dep%2].empty()){
                dep++;
            }
        }
        return dep+1;
    }
};

int main(){


    Solution sol;
    cout<<sol.sortedListToBST(head);
    return 0;
}
