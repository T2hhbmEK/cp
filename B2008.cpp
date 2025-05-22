#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
// #define int long long
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define el '\n'
#define debug(x) cerr << #x << ": " << x << el
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repi(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define peri(i, a, b) for (int i = (b); i >= (a); --i)
#define each(a, x) for (auto& a : x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b) * c;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
