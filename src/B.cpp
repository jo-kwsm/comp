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
  vector<pll> a(n);
  for(ll i=0;i<n;i++) {
    ll v;
    cin >> v;
    a[i]={v,i};
  }
  sort(a.rbegin(),a.rend());
  set<ll> al,ar;
  al.insert(a[0].second);
  ll ans=0;
  for(ll i=1;i<n;i++) {
    ll v=a[i].first;
    ll id=a[i].second;
    vec l(2,-1),r(2,n);
    al.insert(id);
    auto it=al.find(id);
    for(ll i=0;i<2;i++) {
      if(it==al.begin()) break;
      l[i]=*--it;
    }
    it=al.find(id);
    for(ll i=0;i<2;i++) {
      if(++it==al.end()) break;
      r[i]=*it;
    }
    ans+=v*(r[1]-r[0])*(id-l[0]);
    ans+=v*(r[0]-id)*(l[0]-l[1]);
  }
  cout << ans << endl;
}