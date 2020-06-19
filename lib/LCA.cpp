#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct LowestCommonAncestor{
  ll n,h;
  vector< vector<ll> > G,par;
  vector<ll> dep;
  LowestCommonAncestor(){}
  LowestCommonAncestor(ll n):n(n),G(n),dep(n){
    h=1;
    while((1<<h)<=n) h++;
    par.assign(h,vector<ll>(n,-1));
  }

  void add_edge(ll u,ll v){
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }

  void dfs(ll v,ll p,ll d){
    par[0][v]=p;
    dep[v]=d;
    for(ll u:G[v])
      if(u!=p) dfs(u,v,d+1);
  }

  void build(ll r=0){
    dfs(r,-1,0);
    for(ll k=0;k+1<h;k++)
      for(ll v=0;v<n;v++)
        if(~par[k][v])
          par[k+1][v]=par[k][par[k][v]];
  }

  ll lca(ll u,ll v){
    if(dep[u]>dep[v]) swap(u,v);
    for(ll k=0;k<h;k++)
      if((dep[v]-dep[u])>>k&1)
        v=par[k][v];

    if(u==v) return u;

    for(ll k=h-1;k>=0;k--)
      if(par[k][u]!=par[k][v])
        u=par[k][u],v=par[k][v];

    return par[0][u];
  }

  ll distance(ll u,ll v){
    return dep[u]+dep[v]-dep[lca(u,v)]*2;
  }
};

int main() {
  ll n;
  cin >> n;
  LowestCommonAncestor lca(n);//宣言
  for(ll i=0;i<n;i++) {
    ll k;
    cin >> k;
    for(ll j=0;j<k;j++) {
      ll c;
      cin >> c;
      lca.add_edge(i,c);//辺の追加
    }
  }
  lca.build();//構築
  ll q;
  cin >> q;
  for(ll i=0;i<q;i++) {
    ll f,t;
    cin >> f >> t;
    cout << lca.lca(f,t) << endl;//lca計算
  }
}