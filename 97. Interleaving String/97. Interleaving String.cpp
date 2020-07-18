#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class Solution {
    int ***p;
public:
    void init(string s1, string s2, string s3){
        p = new int**[s1.length()+1];
        for(int i = 0;i <= s1.length();i++){
            p[i] = new int*[s2.length()+1];
            for(int j = 0;j <= s2.length();j++){
                p[i][j] = new int[s3.length()+1];
                for(int k = 0;k <= s3.length();k++){
                    p[i][j][k] = -1;
                }
            }
        }
        for(int i = 0;i < s1.length();i++){
            p[i][0][i] = (s1.substr(s1.length()-i, i)==s3.substr(s3.length()-i, i));
        }
        for(int i = 0;i < s2.length();i++){
            p[0][i][i] = (s2.substr(s2.length()-i, i)==s3.substr(s3.length()-i, i));
        }
        p[0][0][0] = 1;
    }

    bool Check(string s1, string s2, string s3){
        int i = s1.length();
        int j = s2.length();
        int k = s3.length();
        int flag1, flag2;
        if(p[i][j][k]==-1){
            if(s1[0]==s3[0])
                flag1 = Check(s1.substr(1,s1.length()-1), s2, s3.substr(1,s3.length()-1));
            else
                flag1 = 0;

            if(s2[0]==s3[0])
                flag2 = Check(s1, s2.substr(1,s2.length()-1), s3.substr(1,s3.length()-1));
            else
                flag2 = 0;

            if(flag1==0&&flag2==0)
                p[i][j][k] = 0;
            else
                p[i][j][k] = 1;
        }

        return p[i][j][k];
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;

        init(s1, s2, s3);

        return Check(s1, s2, s3);
    }
};
int main(){
    /*
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    */

    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbbaccc";

    Solution sol;
    cout<<sol.isInterleave(s1, s2, s3);
    return 0;
}
