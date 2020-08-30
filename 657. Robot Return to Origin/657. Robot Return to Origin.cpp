#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int x;
    int y;
public:
    bool judgeCircle(string moves) {
        x = y = 0;
        int n = moves.size();
        for(int i = 0;i<n;i++){
            if(moves[i]=='U'){
                y++;
            }
            if(moves[i]=='D'){
                y--;
            }
            if(moves[i]=='L'){
                x++;
            }
            if(moves[i]=='R'){
                x--;
            }
        }
        if(x==0 && y==0){
            return true;
        }
        return false;
    }
};
int main(){
    string moves = "UD";
    Solution sol;
    cout<<sol.judgeCircle(moves);
    return 0;
}
