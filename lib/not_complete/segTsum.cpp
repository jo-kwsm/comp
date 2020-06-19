#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//2e5、0-index
const ll max_n = 1<<18;
ll leaf_n;
vector<ll> dat(max_n);
vector<ll> datb(max_n);

// 要素数決定、(1<<31)-1で初期化
void init(ll n) {
  leaf_n=1;
  while(leaf_n<n) leaf_n*=2;
}

// (a,b,x,0,0,leaf_n),[a,b),[0,leaf_n)
void add(ll a, ll b, ll x, ll k=0, ll l=0, ll r=leaf_n) {
  if(a<=l&&r<=b) dat[k]+=x;
  else if(l<b&&a<r){
    datb[k]+=(min(b,r)-max(a,l))*x;
    add(a,b,x,k*2+1,l,(l+r)/2);
    add(a,b,x,k*2+2,(l+r)/2,r);
  }
}

// (a,b,0,0,leaf_n),[a,b),[0,leaf_n)
ll sum(ll a, ll b, ll k=0, ll l=0, ll r=leaf_n) {
  if(r<=a||b<=l) return 0;
  if(a<=l&&r<=b) return dat[k]*(r-l)+datb[k];
  else {
    ll res=(min(b,r)-max(a,l))*dat[k];
    res+=sum(a,b,k*2+1,l,(l+r)/2);
    res+=sum(a,b,k*2+2,(l+r)/2,r);
    return res;
  }
}