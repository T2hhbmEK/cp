#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio cin.tie(nullptr)->sync_with_stdio(false)
// #define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 10;
int n, a[N], ans = -INF;

signed main() {
    fastio;
    cin >> n;
    rep(i, 1, n) {
        cin >> a[i];
        a[i] += max(a[i - 1], 0);
        ans = max(ans, a[i]);
    }
    cout << ans;
    return 0;
}
