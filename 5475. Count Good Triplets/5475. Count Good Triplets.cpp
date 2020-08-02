#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int n;
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c){
        int num = 0;
        n = arr.size();
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                for(int k = j+1;k < n;k++){
                    if(abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                        num++;
                }
            }
        }
        return num;
    }
};

int main(){
    vector<int> arr = {3,0,1,1,9,7};
    int a = 7;
    int b = 2;
    int c = 3;
    Solution sol;
    cout<<sol.countGoodTriplets(arr,a,b,c);
    return 0;
}
