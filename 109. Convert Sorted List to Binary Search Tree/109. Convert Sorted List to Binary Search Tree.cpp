#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    vector<int> lis;
    TreeNode* BST(int low, int high){
        if(low==high){
            return NULL;
        }
        int mid = (low+high)/2;
        TreeNode* left = BST(low, mid);
        TreeNode* right = BST(mid+1, high);

        TreeNode* mm = new TreeNode(lis[mid], left, right);
        return mm;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
         ListNode * p = head;
         while(p){
            lis.push_back(p->val);
            p = p->next;
         }
         return BST(0, lis.size());
    }
};


int main(){


    Solution sol;
    cout<<sol.sortedListToBST(head);
    return 0;
}
