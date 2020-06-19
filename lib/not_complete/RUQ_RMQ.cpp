#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct query{
  ll type;//0=empty, 1=update
  ll value;
  query(ll a=0,ll b=0):type(a),value(b) {}
};

query s[(1<<18)];
ll t[(1<<18)];

void compute(ll k,ll l,ll r){
  query q=s[k];
  s[k].type=0;
  if(q.type==0||r-l==1)return;
  s[k*2+1]=s[k*2+2]=q;  
  t[k*2+1]=t[k*2+2]=q.value;
}

//init update(0,(1<<17),2147483647);
//[a,b)
void update(ll a,ll b,ll x,ll k=0,ll l=0,ll r=(1<<17)){
  if(b<=l || r<=a)return;
  compute(k,l,r);
  if(a<=l && r<=b){
    s[k]=query(1,x);
    t[k]=x;
  }else{
    ll m=(l+r)/2;
    update(a,b,x,k*2+1,l,m);
    update(a,b,x,k*2+2,m,r);
    t[k]=min(t[k*2+1],t[k*2+2]);
  }
}

//[a,b)
ll find(ll a,ll b,ll k=0,ll l=0,ll r=(1<<17)){
  if(b<=l || r<=a)return (1LL<<60);
  compute(k,l,r);
  if(a<=l && r<=b){
    return t[k];
  }else{
    ll m=(l+r)/2;
    ll lv=find(a,b,k*2+1,l,m);
    ll rv=find(a,b,k*2+2,m,r);
    return min(lv,rv);
  }
}



int main(){
  ll n,q,type,a,b,x;
  update(0,(1<<17),2147483647);
  cin >> n >> q;
  while(q--){
    cin >> type;
    if(type==0){
      cin >> a >> b >> x;
      update(a,b+1,x);
    }else{
      cin >> a >> b;
      cout << find(a,b+1) << endl;
    }
  }
  return 0;
}