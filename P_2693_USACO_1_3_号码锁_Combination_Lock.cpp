#include <bits/stdc++.h>
using namespace std;
int n, x[2][3], ans = 1;
int dst(int x, int a) {
    return x > a ? dst(a, x) : min(a - x, x - a + n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 6; ++i) cin >> x[i / 3][i % 3];
    if (n <= 5) return cout << n * n * n, 0;
    for (int i = 0; i < 3; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (dst(j, x[0][i]) <= 2 &&
                dst(j, x[1][i]) <= 2) ++cnt;
        }
        ans *= cnt;
    }
    cout << 250 - ans;
    return 0;
}