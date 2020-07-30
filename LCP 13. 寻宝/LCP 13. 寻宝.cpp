#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
    int m;
    int num_o;
    int num_m;
    int start_x;
    int start_y;
    int target_x;
    int target_y;
    int *o_x;
    int *o_y;
    int *m_x;
    int *m_y;
    int *so;
    int *om;
    int *ms;
    void BFS(int i, int j, vector<string>& maze){

    }
public:
    int minimalSteps(vector<string>& maze){
        n = maze.size();
        m = maze[0].length();
        num_o = 0;
        num_m = 0;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(maze[i][j] == '.'){
                    continue;
                }
                else if(maze[i][j] == 'M'){
                    m_x[num] = i;
                    m_y[num] = j;
                    num_m++;
                }
                else if(maze[i][j] == 'S'){
                    start_x = i;
                    start_y = j;
                }
                else if(maze[i][j] == 'O'){
                    o_x[num_o] = i;
                    o_y[num_o] = j;
                    num_o++;
                }
                else{
                    target_x = i;
                    target_y = j;
                }
            }
        }
    }
};

int main(){
    vector<string> maze = {"S#O", "M..", "M.T"};
    Solution sol;
    cout<<sol.minimalSteps(maze);
    return 0;
}
