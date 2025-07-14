#include <bits/stdc++.h>
#define int __int128
#define endl '\n'
#define sz(x) (int)(x).size()
#define sq(x) (x) * (x)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
ostream& operator<<(ostream& os, const __int128& x) {
  return os << static_cast<ll>(x);
}
istream& operator>>(istream& is, __int128& x) {
  ll a;
  is >> a;
  x = a;
  return is;
}
void Yes() { cout << "Yes" << endl; }
void No() { cout << "No" << endl; }
void Out(ostream& os) { os << endl; }
void Out(ostream& os, int x, auto... args) { os << x << ' ', Out(os, args...); }
void Out(int x, auto... args) { Out(cout, x, args...); }
void Err(int x, auto... args) { Out(cerr, x, args...); }

const int MAXN = 10'000'000;

vector<int> primes;
bitset<MAXN + 1> mp;
void init(int L, int R) {
  mp[0] = mp[1] = true;
  for (int i = 2; sq(i) <= R; ++i) {
    if (!mp[i]) primes.push_back(i);
    for (int j : primes) {
      if (sq(i * j) > R) break;
      mp[i * j] = true;
      if (i % j == 0) break;
    }
  }
  mp.reset();
  for (int i : primes) {
    for (int j = (L - 1 + i) / i * i; j <= R; j += i) {
      mp[j - L] = true;
    }
  }
  for (int i = max(L, (int)2); i <= R; ++i) {
    if (!mp[i - L]) primes.push_back(i);
  }
}

__int128 prevpower(__int128 a, __int128 b) {
  assert(a >= 1 && b > 1);
  if (a < b) return 1;
  __int128 x = prevpower(a, b * b);
  return x * b > a ? x : x * b;
}
__int128 nextpower(__int128 a, __int128 b) {
  return a <= 1 ? 1 : prevpower(a - 1, b) * b;
}

void solve() {  // solution
  int L, R;
  cin >> L >> R;
  init(L, R);
  int ans = 0;
  mp.reset();
  mp[L - L] = true;
  for (int i : primes) {
    int lo = nextpower(L, i), hi = prevpower(R, i);
    for (int j = lo; j <= hi; j *= i) mp[j - L] = true;
  }
  for (int i = L; i <= R; ++i) ans += mp[i - L];
  return Out(ans);
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) solve();
  return 0;
}
