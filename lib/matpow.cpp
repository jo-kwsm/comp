#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll mod=1e9+7;

// size of matrix
ll m;
vec mul(vec &dp, mat &mt) {
  vec ret(m);
  for(ll i=0;i<m;i++) {
    for(ll j=0;j<m;j++) {
      ret[i]=(ret[i]+mt[i][j]*dp[j])%mod;
    }
  }
  return ret;
}

mat matmul(mat &a, mat &b) {
  mat res(m,vec(m,0));
  for(ll i=0;i<m;i++) {
    for(ll j=0;j<m;j++) {
      for(ll k=0;k<m;k++) {
        (res[i][j]+=a[i][k]*b[k][j])%=mod;
      }
    }
  }
  return res;
}

mat update(mat &mt) {
  mat ret(m,vec(m));
  for(ll i=0;i<m;i++) {
    for(ll j=0;j<m;j++) {
      for(ll k=0;k<m;k++) {
        ret[i][j]=(ret[i][j]+mt[i][k]*mt[k][j])%mod;
      }
    }
  }
  return ret;
}

void vmpow(vec &dp,mat &mt, ll k) {
  ll m=dp.size();
  while(k)  {
    if(k&1) dp=mul(dp,mt);
    mt=update(mt);
    k/=2;
  }
}

mat matpow(mat a, ll k) {
  mat res(m,vec(m,0));
  for(ll i=0;i<m;i++) {
    res[i][i]=1;
  }
  while(k>0) {
    if(k&1) res=matmul(res,a);
    a=matmul(a,a);
    k>>=1;
  }
  return res;
}

int main() {
  m=2;
  vec dp(2);
  mat mt(m,vec(m));
  ll k;
  cin >> k >> mod;
  dp[0]=dp[1]=1;
  mt[0][0]=mt[0][1]=mt[1][0]=1;
  vmpow(dp,mt,k);
  cout << dp[1] << endl;
}