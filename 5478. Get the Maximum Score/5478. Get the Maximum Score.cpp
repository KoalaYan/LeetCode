#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int *p[2];
    int n;
    int m;
    int T;
    int maxSum(vector<int>& nums1, vector<int>& nums2, int t,int i){
        if(p[t][i]!=-1)
            return p[t][i];

    }
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2){
        n = nums1.size();
        m = nums2.size();
        T = max(n,m);
        p[0] = new int[T];
        p[1] = new int[T];
        for(int i = 0;i<T;i++){
            p[0][i] = p[1][i] = -1;
        }
        return max(maxSum(nums1, nums2, 0, 0),maxSum(nums1, nums2, 1, 0));
    }
};

int main(){
    vector<vector<int>> grid = {{1,0,0,0,0,0},{0,0,0,1,0,0},{0,0,0,1,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,0,0,1}};
    //vector<vector<int>> grid = {{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};
    //vector<vector<int>> grid = {{0,0},{0,1}};
    Solution sol;
    cout<<sol.minSwaps(grid);
    return 0;
}
