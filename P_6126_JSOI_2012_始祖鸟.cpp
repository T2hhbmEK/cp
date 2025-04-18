#include <bits/stdc++.h>
using namespace std;
const int N = 2E3 + 10;
int n, m, cnt;
bitset<N> a[N], ans;  // n x n+1
void pl(bitset<N> &row, int n) {
    for (int j = 1; j <= n; ++j) cout << row[j];
    cout << "\n";
}
void p() {
    for (int i = 1; i <= n; ++i) {
        pl(a[i], n + 1);
    }
}
bool gaussian_elimination() {
    int rows = n, cols = n + 1;
    for (int j = 1; j <= cols - 1; ++j) {
        for (int i = j; i <= rows; ++i) {
            if (a[i][j]) {
                swap(a[j], a[i]);
                break;
            }
        }
        // cout << "swap\n";
        // p(), cout << "\n";
        if (!a[j][j]) continue;
        for (int i = 1; i <= rows; ++i) {
            if (i != j && a[i][j]) {
                a[i] = a[i] ^ a[j];
            }
        }
        // cout << "eliminate\n";
        // p(), cout << "\n";
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = a[i][n + 1];
        if (!a[i][i] && ans[i]) return false;
        cnt += ans[i];
    }
    // cout << "ans\n";
    // pl(ans, n);
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> m;
        for (int j = 1; j <= m; ++j) {
            int k;
            cin >> k;
            a[i][k] = 1;
        }
        if (m % 2 != 0) {
            a[i][i] = 1;
            a[i][n + 1] = 1;
        }
    }
    bool ok = gaussian_elimination();
    if (!ok) {
        cout << "Impossible\n";
        return 0;
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; ++i) {
        if (ans[i]) cout << i << " ";
    }
    cout << "\n";
    return 0;
}