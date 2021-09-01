#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int *p;
    int IB(int n){
        if(p[n]!=-1)
            return p[n];
        p[n] = 0;
        int temp;
        for(int i = 1;i < n;i++){
            temp = IB(n-i);
            if(temp<n-i)
                temp = n-i;
            if(i*temp>p[n])
                p[n] = i*temp;
        }
        return p[n];
    }
public:
    int integerBreak(int n) {
        p = new int [n+1];

        for(int i = 0;i <= n;i++)
            p[i] = -1;
        p[0] = 0;
        p[1] = 1;
        p[2] = 1;
        return IB(n);
    }
};

int main(){
    int n = 10;
    Solution sol;
    cout<<sol.integerBreak(2);
    return 0;
}
