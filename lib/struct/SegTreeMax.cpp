#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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


// Set,Add,Getmin,Getsum,0-index,[a,b)
int main(){
  ll n,q;
  cin >> n >> q;
  segtree T(n);
  T.Set(0,n,-INF);
  for(ll i=0;i<q;i++){
    ll type,a,b,c;
    cin >> type >> a >> b;
    if(type==0){
      cin >> c;
      T.Set(a,b+1,c);
    }
    else {
      cout << T.Getmax(a,b+1) << endl;
    }
  }
  return 0;
}