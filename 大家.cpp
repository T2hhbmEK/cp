/* 思路：
 * 假设从 i 点出发，经过 l 到 r 这连续的一段区间，最终的开心值最大
 * 那么他要么先走到 l，然后再走到 r，要么先走到 r，然后再走到 l
 * 这样只有一边的点需要走两遍，如果来来回回，某些点需要走两遍以上，得不偿失
 * 那么不妨先算先左走再右走的情况
 * 另一种情况可以把数组倒过来，再算一次
 * 两种情况取最大值即可
 *
 * 那么往左走多远和往右走多远之间没有关系，可以分开算
 * 考虑 i 点往左最多走多远，发现要么在 i 点停着，要么和 i - 1 点走的一样远
 * 那么可以用 DP 计算出来
 * 同理，往右走也是一样的
 *
 * 当然，还要考虑只往一边走不回头的情况
 *
 * 对于另一种情况，只需要把数组倒过来，再算一次即可
 */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
const int maxn = 1e6 + 5;
const ll mod = 1e9;
const ll inf = 1e18;
ll n, v[maxn], l[maxn];
ll dpL[maxn], dpR[maxn];
ll aLR[maxn], a[maxn];
ll ans;
void solve() {
    for (int i = 0; i <= n + 1; ++i) {
        dpL[i] = dpR[i] = aLR[i] = -inf;  // 初始化为负无穷
    }
    // 先左走再右走
    // dpL[i] 表示从 i 往左走又回到 i 的最大开心值
    // 注意最左侧的点不需要回头
    for (int i = 1; i <= n; ++i) {
        dpL[i] = max(dpL[i - 1] + v[i] - 2 * l[i], v[i] - l[i]);
    }
    // dpR[i] 表示从 i 往右走不回头的最大开心值
    for (int i = n; i >= 1; --i) {
        dpR[i] = max(dpR[i + 1], 0LL) + v[i] - l[i];
    }
    // aLR[i] 表示从 i 出发的最大开心值
    for (int i = 1; i <= n; ++i) {
        aLR[i] = max(dpL[i] + dpR[i + 1], dpR[i]);
    }
}
void flip(ll *a) {
    for (int i = 1, j = n; i < j; ++i, --j) {
        swap(a[i], a[j]);
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> l[i];
    }
    solve();
    for (int i = 1; i <= n; ++i) {
        a[i] = aLR[i];
    }
    flip(v);
    flip(l);
    solve();
    flip(aLR);
    for (int i = 1; i <= n; ++i) {
        a[i] = max(aLR[i], a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        ans ^= a[i] + mod;
    }
    cout << ans << endl;
    return 0;
}
