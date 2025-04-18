/* 思路：
 * 1. 二分答案，计算最多能有多少个大于等于 mid 的数
 *    如果大于等于 k 个，将左边界移到中间值，否则将右边界移到中间值的左边
 * 2. 差分数组进行区间修改
 */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
// #define int long long

const ll INF = 1e18;  // 无穷大，用于处理特殊情况
const int maxn = 2e5 + 5;
int n, k, m, ds[maxn];
ll c, d, a[maxn];

int count(ll ans) {
    int cnt = 0;
    // ds 是一个差分数组，用来做区间修改。
    // ds[i] 做前缀和之后的原数组表示
    // 等差数列加到以 i 为起点连续子数组上，增加了多少个大于等于 ans 的数
    for (int i = 1; i <= n; ++i) ds[i] = 0;  // 差分数组清零
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= ans)
            cnt++;
        else {
            ll l = max(i - m + 1, 1);
            ll r = i - (ans <= a[i] + c ? 0
                        : d == 0        ? INF
                                        : (ans - a[i] - c + d - 1) / d);
            if (l > r) continue;  // 无解
            // 以 [l, r] 为起点的等差数列都可以让 a[i] >= ans
            ds[l]++, ds[r + 1]--;
        }
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        ds[i] += ds[i - 1];  // 差分数组前缀和，还原原数组
        cur = max(cur, ds[i]);
    }
    return cur + cnt;
}

void solve() {
    // 读入数据
    cin >> n >> k >> m >> c >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 二分答案
    ll l = 1, r = 1e18;
    while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (count(mid) >= k)
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T;
    //	cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
}
