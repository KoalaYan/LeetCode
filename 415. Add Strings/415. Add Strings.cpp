#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution{
    int n;
    int m;
public:
    string addStrings(string num1, string num2){
        n = num1.length();
        m = num2.length();
        //cout<<n<<' '<<m<<endl;
        string res;
        int carry=0;
        int temp;
        if(n<m){
            res = num2;
            for(int i = m-1;i >= m-n;i--){
                temp = ((res[i]-'0')+(num1[i-m+n]-'0')+carry)/10;
                res[i] = ((res[i]-'0')+(num1[i-m+n]-'0')+carry)%10 + '0';
                //cout<<res[i]<<endl;
                carry = temp;
                //cout<<carry<<endl;
            }
            for(int i = m-n-1;i >= 0;i--){
                temp = ((res[i]-'0')+carry)/10;
                res[i] = ((res[i]-'0')+carry)%10 + '0';
                carry = temp;
            }
            if(carry){
                res = '1'+res;
            }
        }
        else{
            res = num1;
            for(int i = n-1;i >= n-m;i--){
                temp = ((res[i]-'0')+(num2[i-n+m]-'0')+carry)/10;
                //cout<<temp<<endl;
                //cout<<res[i]-'0'<<endl;
                res[i] = ((res[i]-'0')+(num2[i-n+m]-'0')+carry)%10 + '0';
                //cout<<res[i]<<endl;
                carry = temp;
            }
            for(int i = n-m-1;i >= 0;i--){
                temp = ((res[i]-'0')+carry)/10;
                res[i] = ((res[i]-'0')+carry)%10 + '0';
                carry = temp;
            }
            if(carry){
                res = '1'+res;
            }
        }
        return res;
    }
};

int main(){
    string num1 = "98";
    string num2 = "9";
    Solution sol;
    string res = sol.addStrings(num1,num2);
    cout<<res;
    return 0;
}
