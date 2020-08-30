#include"vector"
#include"algorithm"
#include"iostream"
#include"unordered_map"
#include"queue"
using namespace std;

class Solution {
    vector<string> ans;
    unordered_map<string, priority_queue<string, vector<string>,std::greater<string>>> ump;

    void dfs(string curr){
        //ump.find(curr) != ump.end() &&
        while(ump[curr].size() > 0 ){
            string next = ump[curr].top();
            ump[curr].pop();
            dfs(next);
        }
        ans.insert(ans.begin(), curr);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i = 0;i<tickets.size();i++){
            ump[tickets[i][0]].push(tickets[i][1]);
        }
        dfs("JFK");
        return ans;
    }
};

int main(){
    //vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution sol;
    vector<string> res = sol.findItinerary(tickets);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
