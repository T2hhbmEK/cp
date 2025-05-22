#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
// #define int long long
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define debug(x) cerr << #x << ": " << x << endl
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define repa(i, a, n) for (int i = a; i <= (int)(n); ++i)
#define repd(i, a, n) for (int i = a; i >= (int)(n); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const double PI = acos(-1);
const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    int m1 = 0;  // 区间 [0, i) 的最大值
    int m2 = 0;  // 被移动到开头的元素的最大值
    rep(i, n) {
        cin >> a[i];
        if (m1 > a[i]) {
            b[i] = 1;  // 标记为需要移动的元素
            m2 = max(m2, a[i]);
        }
        m1 = max(m1, a[i]);
    }
    // 如果元素小于 m2，则标记为需要移动的元素
    rep(i, n) if (a[i] < m2) b[i] = 1;
    int ans = 0;
    rep(i, n) ans += b[i];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
