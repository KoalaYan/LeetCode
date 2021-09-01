#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;

class node{
public:
    int index;
    node** child;
    vector<int> suffixs;

    node(){
        index = -1;
        child = new node*[26];
        for(int i = 0;i < 26;i++)
            child[i] = NULL;
    }
};

class Solution {
    bool isPalindrome(string s){
        int len = s.length();
        if(!len)
            return true;
        for(int i = 0;i < len/2+1;i++){
            if(s[i]!=s[len-i-1])
                return false;
        }
        return true;
    }
    node* root;
public:
    vector<vector<int>> palindromePairs(vector<string>& words){
        //cout<<"starting...\n";
        vector<vector<int>> res;
        root = new node();
        int n = words.size();
        //building trie
        node* cur;
        for(int i = 0;i < n;i++){
            string s = words[i];
            reverse(s.begin(),s.end());
            cur = root;
            if(isPalindrome(s.substr(0))){
                cur->suffixs.push_back(i);
            }

            int m = s.length();
            //cout<<m<<endl;
            //cout<<i<<endl;
            int pos;
            for(int j = 0;j < m;j++){
                pos = s[j] - 'a';
                //cout<<j<<endl;
                if(!cur->child[pos]){
                    cur->child[pos] = new node();
                }
                cur = cur->child[pos];
                if(isPalindrome(s.substr(j+1))){
                    cur->suffixs.push_back(i);
                }
            }
            cur->index = i;
        }
        //cout<<"test1\n";

        for(int i = 0;i < n;i++){
            string s = words[i];
            cur = root;
            int j;
            int m = s.length();
            int pos;
            for(j = 0;j < m;j++){
                if(cur->index!=-1 && cur->index!=i && isPalindrome(s.substr(j))){
                    res.push_back({i,cur->index});
                }
                pos = s[j] - 'a';
                if(!cur->child[pos])
                    break;
                cur = cur->child[pos];
            }
            if(j==m){
                int num = cur->suffixs.size();
                for(int k = 0;k < num;k++){
                    if(cur->suffixs[k]!=i){
                        res.push_back({i,cur->suffixs[k]});
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    vector<string> words = {"abcd","dcba","lls","s","sssll",""};
    Solution sol;
    vector<vector<int>> res = sol.palindromePairs(words);
    int n = res.size();
    for(int i = 0;i < n;i++){
        cout<<res[i][0]<<' '<<res[i][1]<<endl;
    }
    return 0;
}
