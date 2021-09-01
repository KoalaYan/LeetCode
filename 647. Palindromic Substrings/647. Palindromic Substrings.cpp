#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int num = 0;
        int n = s.length();
        int l, r;
        for(int i = 0;i < 2*n-1;i++){
            l = i/2;
            r = i/2 + i%2;
            while(l>=0 && r<n && s[l]==s[r]){
                num++;
                l--;
                r++;
            }
        }
        return num;
    }
};

int main(){
    Solution sol;
    cout<<sol.countSubstrings("aaa");
    return 0;
}
