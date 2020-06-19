#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

//RollingHash<ll,mod,1777771>
template<typename T,T MOD,T B>
struct RollingHash{
  vector<T> hash,p;
  RollingHash(){}
  RollingHash(const string &s){
    ll n=s.size();
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(ll i=0;i<n;i++){
      hash[i+1]=(hash[i]*B+s[i])%MOD;
      p[i+1]=p[i]*B%MOD;
    }
  }
  //S[l, r)
  T find(ll l,ll r){
    T res=hash[r]+MOD-hash[l]*p[r-l]%MOD;
    return res>=MOD?res-MOD:res;
  }
};

int main() {
  string t,p;
  cin >> t >> p;
  RollingHash<ll,mod,1777771> rt(t);
  RollingHash<ll,mod,1777771> rp(p);
  for(ll i=0;i<(ll)t.size()-(ll)p.size()+1;i++) {
    if(rt.find(i,i+p.size())==rp.find(0,p.size())) {
      cout << i << endl;
    }
  }
}