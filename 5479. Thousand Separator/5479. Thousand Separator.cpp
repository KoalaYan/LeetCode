#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;


class Solution {
public:
    string thousandSeparator(int n) {
        if(n==0)
            return "0";
        char temp;
        string res = "";
        int a = n % 1000;
        int b = n - a;
        while(b){
            temp = (a%10+'0');
            res = temp + res;
            a /= 10;
            temp = (a%10+'0');
            res = temp + res;
            a /= 10;
            temp = (a%10+'0');
            res = temp + res;
            res = '.' + res;
            n /= 1000;
            a = n % 1000;
            b = n - a;
        }
        while(a!=0){
            temp = (a%10+'0');
            //cout<<res<<endl;
            res = temp + res;
            a /= 10;
        }
        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.thousandSeparator(12345);
    return 0;
}
