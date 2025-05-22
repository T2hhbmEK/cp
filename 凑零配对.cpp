#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (int)(b); ++i)

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

bool chk(int x) {
    while (x) {
        if (x % 10 == 0) return true;
        x /= 10;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    REP(i, n) cin >> a[i];
    int ans = 0;
    FOR(i, 0, n - 1) FOR(j, i + 1, n - 1) {
        if (chk(a[i] + a[j])) ans++;
    }
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
