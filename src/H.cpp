#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;

vec ans;
ll n;

void dfs(ll tmp,ll m) {
  if(m==0) {
    ans.push_back(tmp);
  }
  else {
    ll pre=tmp%10;
    for(ll i=pre+1;i<=n;i++) {
      dfs(tmp*10+i,m-1);
    }
  }
}

int main() {
  ll m;
  cin >> n >> m;
  vec a(m);
  for(ll i=0;i<m;i++) cin >> a[i];
  dfs(0,m);
  ll sum=0;
  for(ll i=0;i<m;i++) {
    sum=sum*10+a[i];
  }
  for(ll i=0;i<ans.size();i++) {
    if(ans[i]==sum) {
      cout << i+1 << endl;
      return 0;
    }
  }
}