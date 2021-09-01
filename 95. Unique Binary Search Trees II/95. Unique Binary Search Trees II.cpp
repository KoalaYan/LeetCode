#include"vector"
#include"algorithm"
#include"iostream"
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
    vector<TreeNode*> gT(int low, int high){
        if(low > high){
            return {NULL};
        }
        vector<TreeNode*> all;
        for(int i = low; i <= high;i++){
            vector<TreeNode*> left = gT(low, i-1);
            vector<TreeNode*> right = gT(i+1, high);

            for(auto& l:left){
                for(auto& r:right){
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    all.emplace_back(curr);
                }
            }
        }
        return all;
    }

    vector<TreeNode*> generateTrees(int n){
        if(n==0)
            return {};
        return gT(1, n);
    }
};

int main(){

    return 0;
}
