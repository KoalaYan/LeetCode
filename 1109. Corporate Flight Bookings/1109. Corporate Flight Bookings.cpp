#include"vector"
#include"algorithm"
#include"iostream"
#include"queue"
using namespace std;
#define maxn 1000007

long long Sum[maxn<<2];
long long Add[maxn<<2];
long long A[maxn];

void PushUp(int rt){
    Sum[rt] = Sum[rt<<1]+Sum[rt<<1|1];
}

void Build(int l, int r, int rt){
    if(l==r){
        Sum[rt] = A[l];
        return;
    }
    int m = (l+r)>>1;
    Build(l,m,rt<<1);
    Build(m+1,r,rt<<1|1);
}

void PushDown(int rt, int ln, int rn){
    if(Add[rt]){
        Add[rt<<1]+=Add[rt];
        Add[rt<<1|1]+=Add[rt];
        Sum[rt<<1]+=Add[rt]*ln;
        Sum[rt<<1|1]+=Add[rt]*rn;
        Add[rt]=0;
    }
}

void Update_Interval(int L, int R, int C, int l, int r, int rt){
    if(L <= l && r <= R){
        Sum[rt]+=C*(r-l+1);
        Add[rt]+=C;
        return;
    }
    int m=(l+r)>>1;
    PushDown(rt, m-l+1, r-m);
    if(L<=m){
        Update_Interval(L,R,C,l,m,rt<<1);
    }
    if(R>m){
        Update_Interval(L,R,C,m+1,r,rt<<1|1);
    }
    PushUp(rt);
}

int Query(int L, int R, int l, int r, int rt){
    if(L<=l && r<=R){
        return Sum[rt];
    }
    int m = (l+r)>>1;
    PushDown(rt, m-l+1, r-m);

    int res=0;
    if(L<=m){
        res+=Query(L,R,l,m,rt<<1);
    }
    if(R>m){
        res+=Query(L,R,m+1,r,rt<<1|1);
    }
    return res;
}

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        for(int i = 0;i < maxn;i++){
            A[i]=0;
            Add[i<<1] = Add[i<<1|1] = 0;
        }

        Build(1,n,1);
        vector<int> ANS(n,0);
        int m = bookings.size();
        //cout<<m<<endl;
        for(int i = 0;i < m;i++){
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];
            //cout<<first<<' '<<last<<' '<<seats;
            Update_Interval(first, last, seats, 1, n, 1);
            //cout<<Query(first, last, 1, n, 1)<<endl;
        }
        for(int i = 0;i < n;i++){
            ANS[i] = Query(i+1, i+1, 1, n, 1);
            //cout<<res[i]<<' ';
        }
        return ANS;
    }
};

int main(){
    int n = 2;
    vector<vector<int>> bookings = {{1,2,20},{1,2,50}};
    Solution sol;
    vector<int> res = sol.corpFlightBookings(bookings, n);
    int m = res.size();
    for(int i = 0;i<m;i++){
        cout<<res[i]<<' ';
    }
    return 0;
}
