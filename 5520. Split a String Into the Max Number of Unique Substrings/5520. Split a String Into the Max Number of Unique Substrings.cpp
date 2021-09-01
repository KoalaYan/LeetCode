#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
    vector<string> have;
    int maxUniqueSplit(string s, vector<string> have){
        int n = s.length();
        int m = have.size();
        bool flag;
        int max = 0;
        int temp;
        bool sym = false;
        for(int i = 1;i<n;i++){
            flag = true;
            for(int j = 0;j<m;j++){
                if(s.substr(0,i)==have[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                have.push_back(s.substr(0,i));
                temp = maxUniqueSplit(s.substr(i,n-i),have);
                have.pop_back();
                if(temp>max){
                    max = temp;
                }
            }
        }
        flag = true;
        for(int j = 0;j<m;j++){
            if(s==have[j]){
                flag = false;
                break;
            }
        }
        if(!flag && max==0){
            return 0;
        }
        return max + 1;
    }
public:
    int maxUniqueSplit(string s) {
        return maxUniqueSplit(s,have);
    }
};

int main(){
    string s = "ababccc";
    Solution sol;
    cout<<sol.maxUniqueSplit(s);
    return 0;
}
