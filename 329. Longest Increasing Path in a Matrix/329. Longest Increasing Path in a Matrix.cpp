#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int **p;
    int n;
    int m;
    void init(vector<vector<int>>& matrix){
        n = matrix.size();
        m = matrix[0].size();
        p = new int*[n];
        for(int i = 0;i < n;i++){
            p[i] = new int [m];
            for(int j = 0;j < m;j++){
                p[i][j] = -1;
            }
        }
    }
    int maxPath(int i, int j, vector<vector<int>>& matrix){
        if(p[i][j]!=-1)
            return p[i][j];

        p[i][j] = 0;
        int temp;
        if(i-1>=0){
            if(matrix[i][j]>matrix[i-1][j]){
                temp  = maxPath(i-1,j,matrix);
                if(p[i][j]<temp+1)
                    p[i][j] = temp + 1;
            }
        }

        if(i+1<n){
            if(matrix[i][j]>matrix[i+1][j]){
                temp  = maxPath(i+1,j,matrix);
                if(p[i][j]<temp+1)
                    p[i][j] = temp + 1;
            }
        }

        if(j-1>=0){
            if(matrix[i][j]>matrix[i][j-1]){
                temp  = maxPath(i,j-1,matrix);
                if(p[i][j]<temp+1)
                    p[i][j] = temp + 1;
            }
        }

        if(j+1<m){
            if(matrix[i][j]>matrix[i][j+1]){
                temp  = maxPath(i,j+1,matrix);
                if(p[i][j]<temp+1)
                    p[i][j] = temp + 1;
            }
        }

        return p[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix){
        if(matrix.size()==0){
            return 0;
        }

        init(matrix);

        int maxP = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                //cout<<i<<' '<<j<<endl;
                if(maxP<maxPath(i,j,matrix))
                    maxP = maxPath(i,j,matrix);
            }
        }
        return maxP+1;
    }
};

int main(){
    //vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    vector<vector<int>> matrix = {{3,4,5},{3,2,6},{2,2,1}};
    Solution sol;
    cout<<sol.longestIncreasingPath(matrix);
    return 0;
}
