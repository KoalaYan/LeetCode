#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    bool *vis;
    int n;
    queue<int> que;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        n = rooms.size();
        vis = new bool[n];
        for(int i = 0;i<n;i++){
            vis[i] = false;
        }
        vis[0] = true;
        que.push(0);
        int rec;
        int m;
        while(!que.empty()){
            rec = que.front();
            que.pop();
            m = rooms[rec].size();
            for(int j = 0;j<m;j++){
                if(!vis[rooms[rec][j]]){
                    que.push(rooms[rec][j]);
                    vis[rooms[rec][j]] = true;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    //vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    Solution sol;
    cout<<sol.isBipartite(graph);
    return 0;
}
