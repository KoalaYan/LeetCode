#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

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
    int KMP(string s, string a){
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
        return j;
    }
public:
    string shortestPalindrome(string s) {
        if(!s.length()){
            return s;
        }
        //cout<<s<<endl;
        string temp = s;
        reverse(temp.begin(),temp.end());
        string rs = temp;
        temp = s+"0"+temp;
        getNext(temp);
        //cout<<temp<<endl;
        int l = next[n-1]+1;
        //cout<<l<<endl;
        if(n-l==s.length()){
            return rs + s.substr(l+1,n-l-1);
        }
        else{
            return rs + s.substr(l,n-l);
        }
    }
};


int main(){
    string s = "abcd";
    Solution sol;
    cout<<sol.shortestPalindrome(s);
    return 0;
}
