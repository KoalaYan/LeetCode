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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void visit(TreeNode * root){
    if(!root)
        return;

    visit(root->left);
    cout<<root->val<<endl;
    visit(root->right);
}

class Solution{
    vector<TreeNode*> lis;
    void visit(TreeNode* root){
        if(!root)
            return;
        visit(root->left);
        lis.push_back(root);
        visit(root->right);
    }

public:
    void recoverTree(TreeNode* root){
        visit(root);
        int n = lis.size();
        int i = 0;
        while(i < n-1){
            if(lis[i+1]->val > lis[i]->val){
                i++;
            }
            else{
                break;
            }
        }
        int j = i+1;
        while(j < n && lis[j]->val < lis[i]->val){
            j++;
        }
        j--;
        int temp = lis[i]->val;
        lis[i]->val = lis[j]->val;
        lis[j]->val = temp;
    }
};

int main(){
    TreeNode* l = new TreeNode(2);
    TreeNode* r = new TreeNode(4, l, NULL);
    l = new TreeNode(1);
    TreeNode* root = new TreeNode(3, l, r);

    visit(root);

    Solution sol;
    sol.recoverTree(root);

    visit(root);
    return 0;
}
