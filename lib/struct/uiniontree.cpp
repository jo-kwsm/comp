#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

vec par(2e5+10);
map<ll,ll> si;
void init(ll n) {
  si.clear();
  for(ll i=0;i<n;i++) {
    par[i]=i;
    si[i]=1;
  }
}

ll root(ll x) {
  if(par[x]==x) {
    return x;
  }
  else {
    return par[x]=root(par[x]);
  }
}

ll size(ll x) {
  return si[root(x)];
}

bool same(ll x, ll y) {
  return root(x)==root(y);
}

void unite(ll x, ll y) {
  if(same(x,y)) return;
  ll temp=size(x);
  si[root(y)]+=temp;
  si[root(x)]=0;
  par[root(x)]=root(y);
}