#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    vector<vector<int>> f(n + 1, vector<int>(2, INF));
    f[1][0] = a[1];
    for (int i = 2; i <= n; i++) {
        f[i][0] = min(f[i - 1][0] - a[i - 1] + b[i - 1] + a[i],
                      f[i - 1][1] - b[i - 1] + c[i - 1] + a[i]);
        f[i][1] = min(f[i - 1][0] + b[i], f[i - 1][1] + b[i]);
    }
    cout << min(f[n][0], f[n][1]) << endl;
    return 0;
}
