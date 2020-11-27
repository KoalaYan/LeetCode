#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n = arr.size();
        for(int i = 0;i<=n-m*k;i++){
            vector<int> cmp;
            for(int j = 0;j<m;j++){
                cmp.push_back(arr[i+j]);
            }
            bool flag = true;
            for(int l = 1;l<k;l++){
                for(int j = 0;j<m;j++){
                    if(arr[i+l*m+j]!=cmp[j]){
                        flag = false;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};

int main(){
    int n = 2;
    vector<int> rounds = {2,1,2,1,2,1,2,1,2};
    Solution sol;
    vector<int> res = sol.mostVisited(n, rounds);
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
