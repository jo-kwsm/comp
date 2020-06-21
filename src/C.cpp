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
  ll n;
  cin >> n;
  vec l(n),r(n);
  for(ll i=0;i<n;i++) cin >> l[i] >> r[i];
  sort(l.rbegin(),l.rend());
  sort(r.begin(),r.end());
  ll ans=0;
  ll sum=0;
  for(ll i=0;i<=n/2;i++) {
    if(i) {
      sum+=2*l[i-1]+-2*r[i-1];
    }
    ans=max(ans,sum);
    if(i*2<n) {
      ans=max(ans,(sum+max(2*l[i],-2*r[i])));
    }
  }
  cout << ans << endl;
}