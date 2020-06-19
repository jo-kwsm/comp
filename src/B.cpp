#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<vec,ll> cnt;
  vec tmp(26);
  ll f=0;
  for(ll i=0;i<n;i++) {
    tmp[s[i]-'a']++;
    if(i>=k) {
      tmp[s[i-k]-'a']--;
    }
    if(i>=k-1) {
      if(cnt.count(tmp)&&cnt[tmp]<i-k+1) {
        f=1;
        break;
      }
      if(!cnt.count(tmp)) {
        cnt[tmp]=i;
      }
    }
  }
  if(f) cout << "YES" << endl;
  else cout << "NO" << endl;
}