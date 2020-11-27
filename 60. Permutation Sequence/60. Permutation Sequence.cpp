#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    string res;
    int tan[10];
    void perm(int n, int k, vector<int> &rem){
        if(!n){
            return;
        }
        //cout<<n<<' '<<k<<endl;
        int rec = k / tan[n-1];
        //cout<<rec<<endl;
        char cc = '0'+rem[rec];
        rem.erase(rem.begin()+rec);
        res = res+cc;
        perm(n-1, k % tan[n-1], rem);
    }
public:
    string getPermutation(int n, int k) {
        tan[0] = 1;
        for(int i = 1;i<=n;i++){
            tan[i] = tan[i-1] * i;
        }
        vector<int> rem;
        for(int i = 1;i <= n;i++){
            rem.push_back(i);
        }
        perm(n, k-1, rem);
        return res;
    }
};

int main(){
    Solution sol;
    cout<<sol.getPermutation(4, 9);
    return 0;
}
