#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0)
            return true;

        int i = 0;
        int j = 0;
        int x = s.length();
        int y = t.length();

        while(i!=x && j!=y){
            if(s[i]==t[j++]){
                i++;
            }
        }
        if(i==x){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    string s = "abc";
    string t = "ahbgdc";
    //string s = "axc";
    //string t = "ahbgdc";
    Solution sol;
    cout<<sol.isSubsequence(s, t);
    return 0;
}
