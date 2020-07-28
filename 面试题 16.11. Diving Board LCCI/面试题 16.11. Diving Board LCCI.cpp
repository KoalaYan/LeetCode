#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(!k)
            return {};
        if(shorter==longer)
            return {k*shorter};
        vector<int> res;
        for(int i = k;i >= 0;i--){
            res.push_back(i*shorter+(k-i)*longer);
        }
        return res;
    }
};

int main(){
    int shorter = 1;
    int longer = 2;
    int k = 3;
    Solution sol;
    vector<int> num = sol.divingBoard(shorter,longer,k);
    for(int i = 0;i < num.size();i++)
        cout<<num[i]<<' ';
    return 0;
}
