#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
#include"random"
#include"time.h"

using namespace std;
class Solution {
    int Size;
    int total;
    vector<int> weight;
public:
    Solution(vector<int>& w) {
        Size = w.size();
        weight = w;
        for(int i = 1;i<Size;i++){
            weight[i] += weight[i-1];
        }
        total = weight[Size-1];

    }

    int pickIndex() {
        int p = rand()%total+1;
        return findNum(p, 0 , Size-1);
    }

    int findNum(int n, int l, int r){
        if(l==r){
            return l;
        }
        int m=(l+r)>>1;
        if(weight[m]>=n){
            return findNum(n, l, m);
        }
        else{
            return findNum(n, m+1, r);
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */


