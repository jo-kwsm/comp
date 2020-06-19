#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const ll inf=5e18;

//最大公約数
ll gcd(ll a,ll b) {
  if(b==0) {
    return a;
  }
  else {
    return gcd(b,a%b);
  }
}

//素数判定
bool is_prime(ll n) {
  for(ll i=2;i*i<=n;i++) {
    if(n%i==0) {
      return false;
    }
  }
  return n!=1;
}

//約数列挙
vec divisor(ll n) {
  vector<ll> res;
  for(ll i=1;i*i<=n;i++) {
    if(n%i==0) {
      res.push_back(i);
      if(i!=n/i) {
        res.push_back(n/i);
      }
    }
  }
  return res;
}

//素因数分解
map<ll,ll> prime_factor(ll n) {
  map<ll,ll> res;
  for(ll i=2;i*i<=n;i++) {
    while(n%i==0) {
      res[i]++;
      n/=i;
    }
  }
  if(n!=1) {
    res[n]++;
  }
  return res;
}

//繰り返し自乗法
ll mpow(ll x, ll n) {
  ll ans=1;
  while(n>0) {
    if(n&1) {
      ans=ans*x%mod;
    }
    x=x*x%mod;
    n>>=1;
  }
  return ans;
}

//階乗,factで初期化
vec tfact(1e7+1);
void fact(ll n) {
  for(ll i=0;i<=n;i++) {
    if(i==0) {
      tfact[i]=1;
    }
    else {
      tfact[i]=tfact[i-1]*i%mod;
    }
  }
}

//nCk 繰り返し高速
ll comb(ll n, ll k) {
  return tfact.at(n)*mpow(tfact.at(k),mod-2)%mod*mpow(tfact.at(n-k),mod-2)%mod;
}

//nPk
ll perm(ll n,ll k) {
  return tfact.at(n)*mpow(tfact.at(n-k),mod-2)%mod;
}

//nCk 1回高速
ll comb1(ll n, ll k) {
  ll res=1;
  if(n-k<k) {
    k=n-k;
  }
  for(ll i=n;i>=n-k+1;i--) {
    res=res*i%mod;
  }
  res=res*mpow(tfact[k],mod-2)%mod;
  return res;
}

//nCkをパスカルの三角形を用いて正確に求める nが小さい時 O(n^2)
ll C[51][51];
void comv_table(ll n) {
  for(ll i=0;i<=n;i++) {
    for(ll j=0;j<=i;j++) {
      if(j==0||j==i) {
        C[i][j]=1LL;
      }
      else {
        C[i][j]=(C[i-1][j-1]+C[i-1][j]);
      }
    }
  }
}

//最高位の数を求める
ll sup (ll num) {
  while(num/10>0) {
    num/=10;
  }
  return num;
}

//ランレングス圧縮した配列を返す O(s.size())
typedef pair<char,ll> pcl;
typedef vector<pcl> vpcl;
vpcl rle(string s) {
  vector<pair<char,ll>> res;
  char temp=s[0];
  ll count=0;
  for(ll i=0;i<s.size();i++) {
    if(temp==s[i]) {
      count++;
    }
    else {
      res.push_back(pair<char,ll>(temp,count));
      temp=s[i];
      count=1;
    }
    if(i==s.size()-1) {
      res.push_back(pair<char,ll>(temp,count));
    }
  }
  return res;
}

//トポロジカルソート、数字が大きいと手前
vector<set<ll>> E(1e5+10);
vec sorted(1e5+10,-1);
ll tpl(ll n, ll num) {
  sorted[n]=num;
  for(ll t:E[n]) {
    if(sorted[t]>-1) continue;
    sorted[n]=tpl(t,sorted[n]);
  }
  return sorted[n]+1;
}