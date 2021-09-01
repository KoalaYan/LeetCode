#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    vector<int> shuf = {};
    void seq(){

        int m = shuf.size();



        int temp;
        for(int i = 0;i<m/2;i++){
            temp =  shuf[2*i+1];
            shuf.erase(shuf.begin()+(2*i+1));
            shuf.insert(shuf.begin()+i,temp);
        }
    }
public:
    bool isMagic(vector<int>& target) {
        int n = target.size();
        if(n==1){
            return true;
        }
        int k = 0;
        while(k<n/2){
            if(target[k]==2*(k+1)){
                k++;
            }
            else{
                break;
            }
        }
        if(!k){
            return false;
        }


        if(k>=n/2){
            while(k<n){
                if(target[k]==2*(k-n/2)+1){
                    k++;
                }
                else{
                    break;
                }
            }
        }

        for(int i = 0;i<n;i++){
            shuf.push_back(i+1);
        }
        vector<int> comp;
        while(!shuf.empty()){
            seq();
            for(int i = 0;i<k;i++){
                comp.push_back(shuf[0]);
                shuf.erase(shuf.begin());
                if(shuf.empty()){
                    break;
                }
            }
        }
        for(int i = 0;i<n;i++){

            if(comp[i]!=target[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    int n = 2;
    vector<int> target = {2,4,1,3,5};
    Solution sol;
    cout<<sol.isMagic(target);
    return 0;
}
