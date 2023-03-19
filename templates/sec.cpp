
#include <bits/stdc++.h>
using namespace std;
class str_hashing{
    public:
int mod1=1e9+7;
int mod2=998244353;
int pwr=255;
vector<pair<int,int> > pw;
vector<pair<int,int> > h;
str_hashing(){

}
 str_hashing(string s){
    int n=s.size();
    pw.resize(n+1,pair<int,int>());
    h.resize(n+1,pair<int,int>());
    pw[0].first=1;
    pw[0].second=1;
    for(int i=1;i<=n;i++){
      
        // p[i]=p[i-1]+(s[i-1]-'a'+1)*pw[i]; -->s0+s1*p+s2*p^2+...
        h[i].first=((h[i-1].first*pwr)%mod1+(s[i-1]-'a'+1))%mod1; //----> s0*pL+s1*p^L-1+...
        h[i].second=((h[i-1].second*pwr)%mod2+(s[i-1]-'a'+1))%mod2;
        pw[i].first=(pw[i-1].first*pwr)%mod1;
        pw[i].second=(pw[i-1].second*pwr)%mod2;

    }

    //h[i][l] =h[i+l]-h[i]*pw^l =h[i+1]-pw[l]*h[i]
}
    
    //calc hash of substring i to j
pair<int,int> hash(int i,int j){
    int x=i+1;
    int len=j-i+1;
    return get_hash(x,len);
}
// s1 s2 s3  s4 s5 s6
// s1p^5 s2p^4 s3p^3 s4p^2 s5p^1 s6p^0
//  (s1p^2 s2p^1 s3p^0)*p^3  
                
pair<int,int> get_hash(int i,int len){
    int ans1=(h[i+len-1].first-((pw[len].first*h[i-1].first)%mod1)+mod1)%mod1;
    int ans2=(h[i+len-1].second-((pw[len].second*h[i-1].second)%mod2)+mod2)%mod2;
    return make_pair(ans1,ans2);
}

};
void solve(){
    int n;
    string s;
    cin>>s;
    str_hashing hs(s);
    n=s.size();
    for(int i=0;i<s.size();i++){
        //pre [0-i] len=i+1;
        //suff [n-1 -n-len]
        pair<int,int> h1=hs.hash(0,i);
        int len=i+1;
        cout<<s.substr(0,len)<<" "<<s.substr(n-len,len)<<endl;
        pair<int,int> h2=hs.hash(n-len,n-1);
        if(h1.first==h2.first and h1.second==h2.second){
            cout<<len<<" yes"<<endl;
        }
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