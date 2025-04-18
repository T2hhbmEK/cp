#include <iostream>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int n, a[N], maxn[N], minn[N], d[N], cnt;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // 求出前i个数的最大值
    for (int i = 1; i <= n; i++) {
        maxn[i] = max(a[i], maxn[i - 1]);
    }
    minn[n + 1] = 1e9 + 5;
    // 第i个数～第n个数的最小值
    for (int i = n; i >= 1; i--) {
        minn[i] = min(a[i], minn[i + 1]);
    }
    // 判断某个位置i是否可以作为可划分的点
    for (int i = 1; i < n; i++) {
        if (maxn[i] < minn[i + 1]) {
            d[++cnt] = i;
        }
    }
    int ans = n;
    if (cnt >= 2) {
        for (int i = 1; i < cnt; i++) {
            ans = min(ans, d[i + 1] - d[i]);
        }
    } else {
        ans = -1;
    }
    cout << ans << endl;

    return 0;
}
