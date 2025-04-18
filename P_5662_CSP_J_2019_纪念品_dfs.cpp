#include <bits/stdc++.h>
using namespace std;

int t, n, m, ans;
vector<int> w, v;

void dfs(int k, int m) {
    static vector<int> a(n + 1, 0);
    if (k == n + 1) {
        int sum = m;
        for (int j = 1; j <= n; ++j) {
            sum += a[j] * v[j];
        }
        ans = max(ans, sum);
        return;
    }
    for (int j = 0; j * w[k] <= m; ++j) {
        a[k] = j;
        dfs(k + 1, m - j * w[k]);
        a[k] = 0;
    }
}

int main() {
    cin >> t >> n >> m;
    w.resize(n + 1);
    v.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    t--;
    while (t--) {
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }
        ans = 0;
        dfs(1, m);
        m = ans;
        swap(v, w);
    }
    cout << m << endl;
    return 0;
}
