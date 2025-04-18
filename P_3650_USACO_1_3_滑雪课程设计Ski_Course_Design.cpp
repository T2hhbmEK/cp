#include <bits/stdc++.h>
using namespace std;
const int N = 1E3 + 5;
int n, a[N], ans = INT_MAX;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int amin = *min_element(a, a + n);
    int amax = *max_element(a, a + n);
    int d = amax - amin;
    if (d <= 17) {
        cout << 0;
        return 0;
    }
    for (int l = amin, r = l + 17; r <= amax; ++l, ++r) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += max(l - a[i], 0) * max(l - a[i], 0);
            sum += max(a[i] - r, 0) * max(a[i] - r, 0);
        }
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}