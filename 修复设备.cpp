#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, a[N], f[N], sum, fm = 1e9 + 7;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        f[i] = min(f[i - 1] + a[i], a[i]);
        fm = min(fm, f[i]);
    }
    cout << sum - fm * 2;
    return 0;
}
