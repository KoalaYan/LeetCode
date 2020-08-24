#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;


class Solution {
    bool *flag;
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        flag = new bool[n];
        for(int i = 0;i < n;i++){
            flag[i] = false;
        }
        int m = edges.size();
        int temp;
        for(int i = 0;i < m;i++){
            temp  =edges[i][1];
            flag[temp] = true;
        }
        vector<int> res;
        for(int i = 0;i < n;i++){
            if(!flag[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(){
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};
    Solution sol;
    vector<int> res = sol.findSmallestSetOfVertices(n, edges);
    int m = res.size();
    for(int i = 0;i < m;i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
