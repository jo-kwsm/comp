#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

const ll N=110;
vec x(N),y(N);

bool check(ll a,ll b,ll c) {
  ll x1=x[a]-x[c];
  ll x2=x[b]-x[c];
  ll y1=y[a]-y[c];
  ll y2=y[b]-y[c];
  ll s=abs(x1*y2-x2*y1);
  return s!=0&&s%2==0;
}
 
int main() {
  ll n;
  cin >> n;
  ll ans=0;
  for(ll i=0;i<n;i++) cin >> x[i] >> y[i];
  for(ll i=0;i<n;i++) {
    for(ll j=i+1;j<n;j++) {
      for(ll k=j+1;k<n;k++) {
        if(check(i,j,k)) ans++;
      }
    }
  }
  cout << ans << endl;
}