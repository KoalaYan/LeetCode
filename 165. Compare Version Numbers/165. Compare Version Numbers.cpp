#include"vector"
#include"algorithm"
#include"iostream"
#include"stdio.h"
#include"string.h"
using namespace std;

class Solution {
public:
    vector<int> version(string str){
        vector<int> res;
        char *p;
        char *buff = (char*)str.data();
        //buff=str;
        p = strsep(&buff, ".");
        int num;
        while(p!=NULL)
        {
            num = atoi(p);
            res.push_back(num);
            //cout<<num;
            p = strsep(&buff, ".");
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = version(version1);
        vector<int> v2 = version(version2);
        int n = v1.size();
        int m = v2.size();

        if(n<=m){
            for(int i = 0;i< n;i++){
                if(v1[i]<v2[i]){
                    return -1;
                }
                else if(v1[i]>v2[i]){
                    return 1;
                }
            }
            for(int i = n;i<m;i++){
                if(v2[i]!=0){
                    return -1;
                }
            }
            return 0;
        }
        else{
            for(int i = 0;i< m;i++){
                if(v1[i]<v2[i]){
                    return -1;
                }
                else if(v1[i]>v2[i]){
                    return 1;
                }
            }
            for(int i = m;i<n;i++){
                if(v1[i]!=0){
                    return 1;
                }
            }
            return 0;
        }
    }
};

int main(){
    //vector<int> nums = {3,4,5,1,2};
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution sol;
    cout<<sol.findMin(nums);
    return 0;
}
