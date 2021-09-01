#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
#include<unordered_map>
using namespace std;


class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        int l, r, num;
        for(int i = 0;i<n;i++){
            l = i;
            r = n-i-1;
            num = (l/2+1)*(r/2+1);
            num += ((l+1)/2)*((r+1)/2);
            res += arr[i]*num;
        }
        return res;
    }
};

