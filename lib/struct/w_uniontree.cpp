#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

vector<ll>par(2e5+10);
vector<ll>wei(2e5+10);
void init(ll n) {
  for(ll i=0;i<n;i++) {
    par[i]=i;
  }
}

ll root(ll x) {
  if(par[x]==x) {
    return x;
  }
  else {
    ll r=root(par[x]);
    wei[x]+=wei[par[x]];
    return par[x]=r;
  }
}

ll weight(ll x) {
  root(x);
  return wei[x];
}

bool same(ll x, ll y) {
  return root(x)==root(y);
}

void unite(ll x, ll y, ll w) {
  if(same(x,y)) return;
  w=weight(x)+w-weight(y);
  x=root(x);
  y=root(y);
  par[y]=x;
  wei[y]=w;
}

ll diff(ll x, ll y) {
  return weight(y)-weight(x);
}