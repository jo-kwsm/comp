#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

struct query{
  ll type;//0=empty, 1=add-sum ,2=set-max
  ll value;
  query(ll a=0,ll b=0):type(a),value(b) {}
};

ll INF=(1LL<<60);

struct segtree{
  ll SIZE;
  vector<query> s;
  vector<ll> t;// sum-add
  vector<ll> u;// max-set

  segtree(ll n=1){
    SIZE=1;
    while(SIZE<n)SIZE*=2;
    s.clear();
    t.clear();
    u.clear();
    s.resize(SIZE*2, query());
    t.resize(SIZE*2, 0);
    u.resize(SIZE*2, 0);
  }
  
  void func(ll k,ll l,ll r,query q){
    if(q.type==1){
      if(s[k].type==0)s[k]=q;
      else s[k].value+=q.value;
      t[k]+=q.value*(r-l);
      u[k]+=q.value;
    }
    if(q.type==2){
      s[k]=q;
      t[k]=q.value*(r-l);
      u[k]=q.value;
    }
  }

  void compute(ll k,ll l,ll r){
    query q=s[k];
    s[k]=query();
    if(q.type==0||r-l==1)return;
    ll m=(l+r)/2;
    func(k*2+1,l,m,q);
    func(k*2+2,m,r,q);
  }

  void Update(ll a,ll b,query x,ll k,ll l,ll r){
    if(b<=l || r<=a)return;
    compute(k,l,r);
    if(a<=l && r<=b){
      func(k,l,r,x);
    }else{
      ll m=(l+r)/2;
      Update(a,b,x,k*2+1,l,m);
      Update(a,b,x,k*2+2,m,r);
      t[k]=t[k*2+1]+t[k*2+2];
      u[k]=max(u[k*2+1],u[k*2+2]);
    }
  }

  ll Dfs(ll type,ll a,ll b,ll k,ll l,ll r){
    if(b<=l || r<=a){
      if(type==1)return 0; //add
      if(type==2)return -INF; // max
    }
    compute(k,l,r);
    if(a<=l && r<=b){
      if(type==1)return t[k];
      if(type==2)return u[k];
    }else{
      ll m=(l+r)/2;
      ll lv=Dfs(type,a,b,k*2+1,l,m);
      ll rv=Dfs(type,a,b,k*2+2,m,r);
      if(type==1)return lv+rv; // add
      if(type==2)return max(lv,rv); // max
    }
  }

  void Add(ll a,ll b,ll x){
    Update(a,b,query(1,x), 0,0,SIZE);
  }
  void Set(ll a,ll b,ll x){
    Update(a,b,query(2,x), 0,0,SIZE);
  }
  ll Getsum(ll a,ll b){
    return Dfs(1,a,b, 0,0,SIZE);
  }

  ll Getmax(ll a,ll b){
    return Dfs(2,a,b, 0,0,SIZE);
  }
  
};

ll med_cnt(vec sum) {
  ll res=0;
  ll n=sum.size();
  if(n>1) {
    segtree cnt(2*n+1);
    cnt.Set(0,2*n+1,0);
    for(ll i=0;i<n;i++) {
      res+=cnt.Getsum(0,sum[i]+n+1);
      cnt.Add(sum[i]+n,sum[i]+n+1,1);
    }
  }
  return res;
}

int main() {
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  ll l=1,r=1e9+10;
  while(l+1<r) {
    ll m=(l+r)>>1;
    vec b(n+1);
    for(ll i=0;i<n;i++) {
      if(a[i]>=m) b[i+1]=1;
      else b[i+1]=-1;
    }
    for(ll i=0;i<n;i++) {
      b[i+1]+=b[i];
    }
    ll k=med_cnt(b);
    if(k>=((n+1)*n/2+1)/2) l=m;
    else r=m;
  }
  cout << l << endl;
}