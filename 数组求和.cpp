#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int maxk = 1e4 + 5;

int n, k;
int a[maxn];
int cnt[maxk];

signed main() {
    freopen("array.in", "r", stdin);
    freopen("array.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // 同余前缀和
    for (int i = 1; i <= n; ++i) {
        a[i] = (a[i] + a[i - 1]) % k;
    }
    // 计数
    // 注意要初始化 cnt[0] = 1
    for (int i = 0; i <= n; ++i) {
        cnt[a[i]]++;
    }
    // 计算答案
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += (ll)cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}
