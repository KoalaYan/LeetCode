#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int n;
    int m;
    bool isRight(vector<vector<int>>& image, int sr, int sc, int Color){
        if(sr<0 || sr>=n || sc<0 || sc>=m){
            return false;
        }
        if(image[sr][sc]!=Color){
            return false;
        }
        return true;
    }
    void BFS(vector<vector<int>>& image, int sr, int sc, int newColor){
        int Color = image[sr][sc];
        image[sr][sc] = newColor;
        if(isRight(image, sr-1, sc, Color)){
            BFS(image, sr-1, sc, newColor);
        }
        if(isRight(image, sr+1, sc, Color)){
            BFS(image, sr+1, sc, newColor);
        }
        if(isRight(image, sr, sc-1, Color)){
            BFS(image, sr, sc-1, newColor);
        }
        if(isRight(image, sr, sc+1, Color)){
            BFS(image, sr, sc+1, newColor);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        if(image[sr][sc]==newColor)
            return image;
        BFS(image, sr, sc, newColor);
        return image;
    }
};

void visit(vector<vector<int>> image){
    int n = image.size();
    int m = image[0].size();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<image[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> image = {{0,0,0},{0,1,1}};
    visit(image);
    Solution sol;
    vector<vector<int>> res = sol.floodFill(image, 1, 1, 1);
    visit(res);
    return 0;
}
