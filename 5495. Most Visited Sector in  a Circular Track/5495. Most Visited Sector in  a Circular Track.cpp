#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        int l;
        int r;
        int m = rounds.size();
        if(rounds[0]<=rounds[m-1]){
            l = rounds[0];
            r = rounds[m-1];
            for(int i = l;i <= r;i++){
                res.push_back(i);
            }
        }
        else{
            r = rounds[0]-1;
            l = rounds[m-1]+1;
            for(int i = 1;i <= n;i++){
                if(i<l||i>r)
                    res.push_back(i);
            }
        }

        return res;
    }
};

int main(){
    int n = 2;
    vector<int> rounds = {2,1,2,1,2,1,2,1,2};
    Solution sol;
    vector<int> res = sol.mostVisited(n, rounds);
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
