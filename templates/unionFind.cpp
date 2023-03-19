#include <bits/stdc++.h>
using namespace std;
class unionFind{
    public:
    vector<int> par,rank;
    unionFind(int n){
        par.resize(n+1,0);
        iota(par.begin(),par.end(),0);
        rank.resize(n+1,0);
    }
    int find(int v){
        if(par[v]!=v)return par[v]=find(par[v]);
        return v;
    }
    void merge(int u,int v){
        int comp_u=find(u);
        int comp_v=find(v);
        if(comp_u!=comp_v){
            if(rank[u]>rank[v]){
                par[comp_v]=comp_u;
            }else{
                par[comp_u]=comp_v;
            }
        }
    }
};
void solve(){
    int n;
    cin>>n;
    unionFind uf(n);
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        uf.merge(a,b);
    }
    map<int,vector<int> > mp;
    for(int i=0;i<n;i++){
        mp[uf.find(i)].push_back(i);
    }
   
    for(auto x:mp){
        for(int i=0;i<mp[x.first].size();i++){
            cout<<mp[x.first][i]<<" ";
        }
        cout<<endl;
    }
}
int32_t main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    
    return 0;
}