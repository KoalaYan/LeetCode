#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int ***dp;
    int calPoints(vector<int>& boxes, int left, int right, int k){
        //cout<<left<<' '<<right<<k<<endl;
        if(left > right)
            return 0;
        if(dp[left][right][k]!=0)
            return dp[left][right][k];
        dp[left][right][k] = calPoints(boxes, left, right-1, 0) + (k+1)*(k+1);
        for(int i = left;i < right;i++){
            if(boxes[i] == boxes[right]){
                dp[left][right][k] = max(dp[left][right][k], calPoints(boxes, left, i, k+1) + calPoints(boxes, i+1, right-1, 0));
            }
        }
        return dp[left][right][k];
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        //cout<<"in\n";
        dp = new int **[n];
        for(int i = 0;i < n;i++){
            dp[i] = new int *[n];
            for(int j = 0;j < n;j++){
                dp[i][j] = new int [n];
                for(int k = 0;k < n;k++){
                    //cout<<i<<' '<<j<<' '<<k<<endl;
                    dp[i][j][k] = 0;
                }
            }
        }
        return calPoints(boxes, 0, boxes.size()-1, 0);
    }
};

int main(){
    vector<int> boxes = {1,3,2,2,2,3,4,3,1};
    //cout<<boxes[0]<<endl;
    Solution sol;
    int res = sol.removeBoxes(boxes);
    cout<<res;
    return 0;
}
