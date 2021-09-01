#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    vector<string> res;
    void proc(string a, string s, int j){
        if(j==0 && s.size()==0){
            res.push_back(a.substr(0, a.length() - 1));
        }
        int t[4];
        t[0] = 0;
        int n = s.size();
        if(n>3)
            n = 3;
        for(int i = 0;i < n;i++){
            t[i+1] = t[i]*10 + s[i] - '0';
            if(t[i+1]>=0 && t[i+1]<=255){
                proc(a+s.substr(0,i+1)+'.', s.substr(i+1,s.length()-i-1), j-1);
            }
            if(t[i+1]==0)
                break;
        }
    }
    int str2int(string s){
        int n = s.size();
        int res = 0;
        for(int i = 0;i < n;i++){
            res = res*10 + s[i] - '0';
        }
        //cout<<res<<endl;
        return res;
    }
    vector<string> jesus(string s){
        if(s.size()>12)
            return res;
        int n = s.size();
        int s1, s2, s3, s4;
        for(int i = 1;i < 4;i++){
            for(int j = 1;j < 4;j++){
                for(int k = 1;k < 4;k++){
                    for(int l = 1;l < 4;l++){
                        if(i+j+k+l>n)
                            break;
                        if(i+j+k+l==n){
                            s1 = str2int(s.substr(0,i));
                            s2 = str2int(s.substr(i,j));
                            s3 = str2int(s.substr(i+j,k));
                            s4 = str2int(s.substr(i+j+k,l));
                            if(s1>255 || s2>255 || s3>255 || s4>255)
                                break;
                            res.push_back(s.substr(0,i)+'.'+s.substr(i,j)+'.'+s.substr(i+j,k)+'.'+s.substr(i+j+k,l));
                        }
                        if(s[i+j+k]=='0')
                            break;
                    }
                    if(s[i+j]=='0')
                        break;
                }
                if(s[i]=='0')
                    break;
            }
            if(s[0]=='0')
                break;
        }
        return res;

        for(int i = 1;i < 4;i++){
            if(i>n)
                break;
            s1 = str2int(s.substr(0,i));
            if(s1>255)
                break;
            for(int j = 1;j < 4;j++){
                if(i+j>n)
                    break;
                s2 = str2int(s.substr(i,j));
                if(s2>255)
                    break;
                for(int k = 1;k < 4;k++){
                    if(i+j+k>n)
                        break;
                    s3 = str2int(s.substr(i+j,k));
                    if(s3>255)
                        break;
                    for(int l = 1;l < 4;l++){
                        if(i+j+k+l>n)
                            break;
                        cout<<i<<' '<<j<<' '<<k<<' '<<l<<endl;
                        s4 = str2int(s.substr(i+j+k,l));
                        if(s4>255)
                            break;
                        if(i+j+k+l==n){
                            res.push_back(s.substr(0,i)+'.'+s.substr(i,j)+'.'+s.substr(i+j,k)+'.'+s.substr(i+j+k,l));
                        }
                        if(s[i+j+k]=='0')
                            break;
                    }
                    if(s[i+j]=='0')
                        break;
                }
                if(s[i]=='0')
                    break;
            }
            if(s[0]=='0')
                break;
        }
        return res;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        return jesus(s);
        if(s.size()>12)
            return res;
        proc("", s, 4);
        return res;
    }
};

int main(){
    string s = "010010";
    Solution sol;
    vector<string> res = sol.restoreIpAddresses(s);
    int n = res.size();
    for(int i = 0;i < n;i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
