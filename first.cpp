#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int seg[4*MAXN]={0};
#define int long long
void build(vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2+1, tl, tm);
        build(a, v*2+2, tm+1, tr);
        seg[v] = seg[v*2+1] + seg[v*2+2];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return seg[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2+1, tl, tm, l, min(r, tm))
           + sum(v*2+2, tm+1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        seg[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2+1, tl, tm, pos, new_val);
        else
            update(v*2+2, tm+1, tr, pos, new_val);
        seg[v] = seg[v*2+1] + seg[v*2+2];
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n),v;
    for(auto &x: a)cin>>x;
    map<int,int> mp;
    for(int i=0;i<q;i++){
        char t;
        int b,c;
        cin>>t>>b>>c;
        if(t=='1'){
            v.push_back()
        }else{

        }
    }
    
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}