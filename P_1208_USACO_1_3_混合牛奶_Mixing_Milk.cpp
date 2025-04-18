#include <bits/stdc++.h>
using namespace std;
const int N = 2E6 + 5;
int n, m, ans;
struct T {
    int p, a;
} pa[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> pa[i].p >> pa[i].a;
    }
    sort(pa, pa + m, [](T& x, T& y) { return x.p < y.p; });
    for (int i = 0; n > 0 && i < m; ++i) {
        if (pa[i].a >= n) {
            ans += pa[i].p * n;
            n = 0;
        } else {
            ans += pa[i].p * pa[i].a;
            n -= pa[i].a;
        }
    }
    cout << ans;
    return 0;
}