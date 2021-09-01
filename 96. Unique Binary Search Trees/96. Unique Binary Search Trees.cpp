#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int *tree;
public:
    int DP(int n){
        if(tree[n]==0){
            for(int i = 0;i < n;i++)
                tree[n] += DP(i) * DP(n-i-1);
        }
        return tree[n];
    }

    int numTrees(int n) {
        tree = new int[n+1];
        tree[0] = tree[1] = 1;
        for(int i = 2;i <= n;i++)
            tree[i] = 0;
        return DP(n);
    }
};

int main(){
    Solution sol;
    cout<<sol.numTrees(3);
    return 0;
}
