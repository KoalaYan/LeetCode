#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    int *p;
public:
    bool win(int N){
        if(p[N]==-1){
            p[N] = 0;
            bool flag;
            for(int i = 1;i < N;i++){
                if(N%i==0){
                    flag = win(N-i);
                    if(flag){
                        p[N] = 1;
                    }
                }
            }
        }
        return p[N];
    }

    bool divisorGame(int N){
        p = new int[N+1];
        p[2] = 1;
        p[3] = 0;
        for(int i = 4;i <= N;i++){
            p[i] = -1;
        }
        return win(N);
    }
};

int main(){
    int N = 4;
    Solution sol;
    cout<<sol.divisorGame(N);
    return 0;
}
