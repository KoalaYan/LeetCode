#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
    int **p;
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        if(n==0)
            return 0;
        p = new int*[n];
        for(int i = 0;i < n;i++){
            p[i] = new int [3];
        }
        p[0][0] = -prices[0];
        p[0][1] = p[0][2] = 0;
        for(int i = 1;i < n;i++){
            p[i][0] = max(p[i-1][0], p[i-1][2]-prices[i]);
            p[i][1] = p[i-1][0] + prices[i];
            p[i][2] = max(p[i-1][1], p[i-1][2]);
            //cout<<i<<' '<<p[i][0]<<' '<<p[i][1]<<' '<<p[i][2]<<endl;
        }
        return max(p[n-1][1], p[n-1][2]);
    }
};

int main(){
    vector<int> prices = {1,2,3,0,2};
    Solution sol;
    cout<<sol.maxProfit(prices);
    return 0;
}
