#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int n;
    bool *visit;
    bool *group;
public:
    void init(vector<vector<int>>& graph){
        n = graph.size();
        visit = new bool[n];
        group = new bool[n];
        for(int i = 0;i < n;i++){
            visit[i] = group[i] = false;
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        init(graph);
        queue<int> que;
        for(int i = 0;i < n;i++){
            if(!visit[i]){
                group[i] = false;
                visit[i] = true;
                que.push(i);
                while(!que.empty()){
                    int u = que.front();
                    que.pop();
                    int v;
                    for(int j = 0;j < graph[u].size();j++){
                        v = graph[u][j];
                        if(!visit[v]){
                            group[v] = (!group[u]);
                            visit[v] = true;
                            que.push(v);
                        }
                        else{
                            if(group[v]==group[u]){
                                return false;
                            }
                        }
                    }
                }
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
