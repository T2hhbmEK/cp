#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 10;

int solve(int a[], int n, int t) {
    int sum = 0;
    int avg = t / n;
    for (int i = 1; i <= n; i++) {
        a[i] -= avg;
        a[i] += a[i - 1];
    }
    sort(a + 1, a + 1 + n);
    int k = (1 + n) / 2;
    for (int i = 1; i <= n; i++) {
        sum += abs(a[i] - a[k]);
    }
    return sum;
}

int n, m, t;
int row[N], col[N];
int ans;

signed main() {
    cin >> n >> m >> t;
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        row[x]++;
        col[y]++;
    }
    bool flag_row = t % n == 0;
    bool flag_col = t % m == 0;
    if (flag_row) {
        ans += solve(row, n, t);
    }
    if (flag_col) {
        ans += solve(col, m, t);
    }
    if (flag_col && flag_row) {
        cout << "both " << ans;
    } else if (flag_row) {
        cout << "row " << ans;
    } else if (flag_col) {
        cout << "column " << ans;
    } else {
        cout << "impossible";
    }
    return 0;
}