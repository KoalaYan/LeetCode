#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> word;
        int len = text.length();
        int n = 0;
        string s = "";
        for(int i = 0;i<len;i++){
            if(text[i]==' '){
                if(s.length()){
                    word.push_back(s);
                    s = "";
                }
                n++;
            }
            else{
                s = s+text[i];
            }
        }
        if(s.length()){
            word.push_back(s);
        }
        int k = 0;
        if(word.size()>1){
            k = n / (word.size()-1);
            cout<<word.size();
        }
        string res = word[0];
        if(!n){
            return res;
        }
        for(int i = 1;i<word.size();i++){
            for(int j = 0;j<k;j++){
                res = res+" ";
            }
            res = res+word[i];

        }
        for(int i = 0;i<n-(word.size()-1)*k;i++){
            res = res+" ";
        }
        return res;
    }
};

int main(){
    string text = "a";
    Solution sol;
    cout<<sol.reorderSpaces(text);
    return 0;
}
