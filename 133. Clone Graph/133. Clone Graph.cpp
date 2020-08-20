#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    bool flag[101];
    Node* arr[101];
    Node* dfs(Node* cur, Node* node){
        if(!flag[cur->val]){
            flag[cur->val] = true;
            int n = node->neighbors.size();
            Node*temp;
            int val;
            for(int i = 0;i < n;i++){
                val = node->neighbors[i]->val;
                if(arr[val]!=NULL){
                    temp = arr[val];
                }
                else{
                    temp = new Node(val);
                    arr[val] = temp;
                }
                cur->neighbors.push_back(temp);
                dfs(temp, node->neighbors[i]);
            }
        }
        return cur;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        for(int i = 1;i < 101;i++){
            flag[i] = false;
            arr[i] = NULL;
        }
        Node* cur = new Node(node->val);
        arr[cur->val] = cur;
        return dfs(cur, node);
    }
};

int main(){

    Solution sol;
    Node *cur = sol.cloneGraph(node);
    return 0;
}
