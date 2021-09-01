#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
    int *next;
    void getNext(string s){
        n = s.length();
        next = new int[n];
        next[0] = -1;
        int i = 0;
        int j = -1;
        while(i<n-1){
            //cout<<i<<endl;
            if(j==-1 || s[i]==s[j]){
                i++;
                j++;
                next[i] = j;
            }
            else{
                j = next[j];
            }
        }
    }
    bool KMP(string s, string a){
        int i = 0;
        int j = -1;
        int n = s.length();
        int m = a.length();
        while(i<n-1 && j<m){
            if(j==-1 || s[i]==a[j]){
                i++;
                j++;
            }
            else{
                j = next[j];
            }
        }
        if(j==m)
            return true;
        return false;
    }
public:
    bool repeatedSubstringPattern(string s) {
        getNext(s+s);
        return KMP(s+s, s);
    }
};

int main(){
    Solution sol;
    cout<<sol.repeatedSubstringPattern("abcdabd");
    return 0;
}
