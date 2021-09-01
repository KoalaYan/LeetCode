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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p){
            if(q)
                return false;
            else
                return true;
        }
        else{
            if(!q)
                return false;
        }
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        que1.push(p);
        que2.push(q);

        TreeNode* x;
        TreeNode* y;

        while(!que1.empty()&&!que2.empty()){
            x = que1.front();
            y = que2.front();
            que1.pop();
            que2.pop();
            if(x->val != y->val)
                return false;
            if(x->left){
                if(y->left){
                    que1.push(x->left);
                    que2.push(y->left);
                }
                else{
                    return false;
                }
            }
            else{
                if(y->left){
                    return false;
                }
            }

            if(x->right){
                if(y->right){
                    que1.push(x->right);
                    que2.push(y->right);
                }
                else{
                    return false;
                }
            }
            else{
                if(y->right){
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    TreeNode* l = new TreeNode(2);
    TreeNode* r = NULL;
    TreeNode* p = new TreeNode(1, l, r);
    l = NULL;
    r = new TreeNode(2);
    TreeNode* q = new TreeNode(1, l, r);

    Solution sol;
    cout<<sol.isSameTree(p, q);
    return 0;
}
