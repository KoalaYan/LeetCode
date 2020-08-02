#include"vector"
#include"algorithm"
#include"iostream"
#include"stack"
using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root){
        stack<TreeNode*> sck;
        if(!root)
            return;
        if(root->right)
            sck.push(root->right);
        if(root->left)
            sck.push(root->left);
        TreeNode* p;
        TreeNode* cur = root;
        while(!sck.empty()){
            p = sck.top();
            sck.pop();
            cur->left = NULL;
            cur->right = p;
            cur = p;
            if(p->right)
                sck.push(p->right);
            if(p->left)
                sck.push(p->left);
        }
    }
};

int main(){
    TreeNode* rl = nullptr;
    TreeNode* rr = new TreeNode(6);
    TreeNode* ll = new TreeNode(3);
    TreeNode* lr = new TreeNode(4);
    TreeNode* l = new TreeNode(2,ll,lr);
    TreeNode* r = new TreeNode(5,rl,rr);
    TreeNode* root = new TreeNode(1,l,r);


    Solution sol;
    sol.flatten(root);
    while(root!=NULL){
        cout<<root->val<<' ';
        root = root->right;
    }
    return 0;
}
