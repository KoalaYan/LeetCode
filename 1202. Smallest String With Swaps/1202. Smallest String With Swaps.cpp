#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
#include<unordered_map>
using namespace std;



class Solution {
    int *pre;
    int n;
    bool *flag;

    int Find(int x){
        if(x==pre[x]) return x;
        return pre[x]=Find(pre[x]);
    }

    void Merge(int x,int y){
        int fx=Find(x),fy=Find(y);
        if(fx!=fy) pre[fx]=fy;
    }

    string sortString(string s, vector<int> index){
        int n = index.size();
        for(int i = 0;i < n;i++){
            int idx = index[i];
            for(int j = i;j < n;j++){

            }
        }
        for (int i=0; i<n-1; i++){
            for (int j=0; j<n-1-i; j++){
                int jj = index[j];
                int jjp = index[j+1];
                if (s[jj] > s[jjp]){
                    char temp = s[jj];
                    s[jj] = s[jjp];
                    s[jjp] = temp;
                }
            }
        }
        return s;
    }

public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n = s.size();
        pre = new int[n];
        flag = new bool[n];

        for(int i = 0;i < n;i++){
            pre[i] = i;
            flag[i] = true;
        }


        int x;
        int y;
        for(int i = 0;i < pairs.size();i++){
            x = pairs[i][0];
            y = pairs[i][1];
            Merge(x, y);
        }

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[Find(i)].emplace_back(s[i]);
        }
        for (auto& [x, vec] : mp) {
            sort(vec.begin(), vec.end(), greater<int>());
        }
        for (int i = 0; i < s.length(); i++) {
            int x = Find(i);
            s[i] = mp[x].back();
            mp[x].pop_back();
        }

        return s;
    }
};

int main(){
    string s = "cba";
    vector<vector<int>> pairs = {{0,1},{1,2}};
    Solution sol;
    cout<<sol.smallestStringWithSwaps(s, pairs);
    return 0;
}
