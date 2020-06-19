#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<string> s(n);
  for(ll i=0;i<n;i++) {
    cin >> s[i];
    sort(s[i].begin(),s[i].end());
  }
  map<string,ll> cnt;
  ll ans=0;
  for(ll i=0;i<n;i++) {
    if(cnt.count(s[i])) {
      ans+=cnt[s[i]];
    }
    cnt[s[i]]++;
  }
  cout << ans << endl;
}