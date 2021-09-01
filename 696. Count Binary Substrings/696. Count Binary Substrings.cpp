#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int better(string s){
        int res = 0;
        vector<int> que;
        int i = 1;
        char pre = s[0];
        int num = 1;
        int n = s.length();
        while(i<n){
            if(s[i]==pre){
                num++;
                i++;
            }
            else{
                que.push_back(num);
                num=1;
                pre=s[i];
                i++;
            }
        }
        que.push_back(num);
        n = que.size();
        for(int i = 0;i < n-1;i++){
            res += min(que[i], que[i+1]);
        }
        return res;
    }
public:
    int countBinarySubstrings(string s) {
        return better(s);
        int res = 0;
        int i = 0;
        int j = -1;
        int x = 0;
        int y = 0;
        int n = s.length();
        while(i+1<n && j+1<n){
            //cout<<x<< ' '<<y<<endl;
            res += min(x, y);
            i = j+1;
            if(i>=n){
                x = 0;
                break;
            }
            x = 1;
            while(i+1<n && s[i]==s[i+1]){
                x++;
                i++;
            }
            //cout<<"i="<<i<<endl;
            //cout<<x<< ' '<<y<<endl;
            res += min(x, y);
            j = i+1;
            if(j>=n){
                y = 0;
                break;
            }
            y = 1;
            while(j+1<n && s[j]==s[j+1]){
                y++;
                j++;
            }
            //cout<<"j="<<j<<endl;
        }
        //cout<<x<< ' '<<y<<endl;
        res += min(x, y);
        return res;
    }
};

int main(){
    string s = "00110011";
    Solution sol;
    cout<<sol.countBinarySubstrings(s);
    return 0;
}
