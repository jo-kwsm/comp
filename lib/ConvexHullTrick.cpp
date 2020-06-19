#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

struct ConvexHullTrick {
    struct Line {
        long long a, b;
        long long get(long long x) { return a * x + b; }
    };
    deque<Line> que;
    bool check(Line a, Line b, Line c) {
        return (b.b - c.b) * (b.a - a.a) <= (a.b - b.b) * (c.a - b.a);
    }
    void add(long long a, long long b) {
        Line l{a, b};
        while(que.size() > 1 && check(que[que.size() - 2], que.back(), l))
            que.pop_back();
        que.push_back(l);
    }
    long long query(long long x) {
        if(que.empty()) return INT64_MAX;
        while(que.size() > 1 && que[0].get(x) >= que[1].get(x))
            que.pop_front();
        return que[0].get(x);
    }
};

int main() {
  ll n,c;
  ConvexHullTrick cht;
  cin >> n >> c;
  vec h(n);
  vec dp(n);
  for(ll i=0;i<n;i++) cin >> h[i];
  cht.add(-2*h[0],h[0]*h[0]);
  for(ll i=1;i<n;i++) {
    dp[i]=cht.query(h[i])+h[i]*h[i]+c;
    cht.add(-2*h[i],dp[i]+h[i]*h[i]);
  }
  cout << dp[n-1] << endl;
}