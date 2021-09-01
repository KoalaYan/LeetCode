#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int n;
public:
    int maxNum(vector<int>& arr){
        int maxN = arr[0];
        for(int i = 1;i < n;i++)
            if(maxN<arr[i])
                maxN = arr[i];
        return maxN;
    }
    int getWinner(vector<int>& arr, int k){
        int maxN = arr[0];
        int times = 0;
        int total = 1;
        n = arr.size();
        if(k>=n-1){
            return maxNum(arr);
        }
        while(total<n && times<k){
            if(arr[total]<maxN){
                times++;
                total++;
            }
            else{
                times = 1;
                maxN = arr[total];
                total++;
            }
        }

        return maxN;
    }
};

int main(){
    vector<int> arr = {2,1,3,5,4,6,7};
    int k = 2;
    Solution sol;
    cout<<sol.getWinner(arr,k);
    return 0;
}
