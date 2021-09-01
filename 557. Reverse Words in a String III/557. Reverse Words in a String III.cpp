#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int l = 0;
        int r = 0;
        int rec;
        int n = s.length();
        if(!n)
            return s;
        char temp;
        while(1){
            while(r+1<n && s[r+1]!=' '){
                r++;
            }
            rec = r+1;
            while(l<r){
                temp = s[r];
                s[r] = s[l];
                s[l] = temp;
                r--;
                l++;
            }
            if(rec==n){
                break;
            }
            l = r = rec+1;
        }
        return s;
    }
};

int main(){
    string s = "Let's take LeetCode contest";
    Solution sol;
    cout<<sol.reverseWords(s);
    return 0;
}
