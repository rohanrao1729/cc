
#include <bits/stdc++.h>
using namespace std;
class string_algo{
    public:

vector<int> p;
vector<int> z;
// if flag is sent true then kmp and if flag is false z algorithm
 string_algo(string s,bool flag){
    int n=s.size();
    if(flag){
    p.resize(n+1,0);
        kmp(s);
    }else{
        z.resize(n+1,0);
        zAlgo(s);
    }

}
 void kmp(string s){
    int n=s.size();
    for (int i = 1; i < n; i++) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j])
            j = p[j-1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }

 }
 void zAlgo(string s){
    int n = (int) s.length();
    
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }

 }
    
 

};
void solve(){
    int n;
    string s;
    cin>>s;
    string_algo alg(s,false);
    for(int i=0;i<alg.z.size();i++){
        cout<<alg.z[i]<<" ";
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