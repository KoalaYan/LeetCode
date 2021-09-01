#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int n;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        vector<int> course[n];

        int temp;
        for(int i = 0;i < prerequisites.size();i++){
            temp = prerequisites[i][0];
            course[temp].push_back(prerequisites[i][1]);
        }
        queue<int> que;
        bool flag[n];
        for(int j = 0;j < n;j++){
            for(int i = 0;i < n;i++)
                flag[i] = false;
            que.push(j);
            while(!que.empty()){
                temp = que.front();
                que.pop();
                for(int i = 0;i < course[temp].size();i++){
                    if(course[temp][i]==j)
                        return false;
                    else if(flag[course[temp][i]]==true)
                        continue;
                    else{
                        que.push(course[temp][i]);
                        flag[course[temp][i]] = true;
                    }
                }
            }
        }

        return true;
    }
};

int main(){
    vector<vector<int>> prerequisites = {{0,1},{3,1},{1,3},{3,2}};
    int numCourses = 4;
    Solution sol;
    cout<<sol.canFinish(numCourses, prerequisites);
    return 0;
}
