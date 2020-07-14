#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int n;
    int **p;
public:
    void init(vector<vector<int>>& triangle){
        n = triangle.size();
        //cout<<"n:"<<n<<endl;
        //cout<<"m:"<<m<<endl;
        p = new int*[2];
        p[0] = new int [n];
        p[1] = new int [n];
        p[0][0] = triangle[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        init(triangle);
        if(n==1)
            return triangle[0][0];
        //cout<<"finish initializing\n";
        for(int i = 1;i < n-1;i++){
            p[i%2][0] = p[(i-1)%2][0] + triangle[i][0];
            p[i%2][i] = p[(i-1)%2][i-1] + triangle[i][i];
            //cout<<i<<','<<0<<'='<<p[i%2][0]<<endl;
            for(int j = 1;j < i;j++){
                int temp1 = p[(i-1)%2][j-1] + triangle[i][j];
                int temp2 = p[(i-1)%2][j] + triangle[i][j];
                if(temp1<temp2){
                    p[i%2][j] = temp1;
                }
                else{
                    p[i%2][j] = temp2;
                }
                //cout<<i<<','<<j<<'='<<p[i%2][j]<<endl;
            }
            //cout<<i<<','<<i<<'='<<p[i%2][i]<<endl;
        }
        //cout<<"finish for-loop\n";
        int mini;
        int i = n-1;
        p[i%2][0] = p[(i-1)%2][0] + triangle[i][0];
        //cout<<i<<','<<0<<'='<<p[i%2][0]<<endl;
        mini = p[(n-1)%2][0];
        p[i%2][i] = p[(i-1)%2][i-1] + triangle[i][i];
        for(int j = 1;j < n-1;j++){
            int temp1 = p[(i-1)%2][j-1] + triangle[i][j];
            int temp2 = p[(i-1)%2][j] + triangle[i][j];
            if(temp1<temp2){
                p[i%2][j] = temp1;
            }
            else{
                p[i%2][j] = temp2;
            }
            //cout<<i<<','<<j<<'='<<p[i%2][j]<<endl;
            if(p[(n-1)%2][j]<mini){
                mini = p[(n-1)%2][j];
            }
        }
        //cout<<i<<','<<i<<'='<<p[i%2][i]<<endl;
        if(p[(n-1)%2][n-1]<mini){
            mini = p[(n-1)%2][n-1];
        }
        return mini;
    }
};

int main(){
    //vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    vector<vector<int>> triangle = {{-10}};
    Solution sol;
    cout<<sol.minimumTotal(triangle);
    return 0;
}
