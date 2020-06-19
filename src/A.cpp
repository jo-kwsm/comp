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
  ll n=100;
  vec x(n+1),y(n+1);
  ll p=0;
  for(ll h=0;h<1500;h+=300) {
    for(ll w=0;w<1500;w+=300) {
      x[100-p]=w+(100-p);
      y[100-p]=h+(100-p);
      x[51+p]=w+300-(51+p);
      y[51+p]=h+300-(51+p);
      x[50-p]=w+300-(50-p);
      y[50-p]=h+(50-p);
      x[1+p]=w+(1+p);
      y[1+p]=h+300-(p+1);
      p++;
    }
  }
  for(ll i=1;i<=n;i++) {
    cout << x[i] << " " << y[i] << endl;
  }
}