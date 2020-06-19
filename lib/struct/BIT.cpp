#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// 1-index
ll BIT_size=2e5+10;
vector<ll> BIT(BIT_size);

// [a]+w
void add(ll a, ll w) {
  for(ll x=a;x<=BIT_size;x += x & -x) {
    BIT[x]+=w;
  }
}

// [a,b]
ll sum(ll a, ll b) {
  ll res=0;
  if(a>1) {
    for(ll x=a-1;x>0;x -= x & -x) {
      res-=BIT[x];
    }
  }
  for(ll x=b;x>0;x -= x & -x) {
    res+=BIT[x];
  }
  return res;
}