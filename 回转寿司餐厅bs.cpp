#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int n, m;
pii a[MAXN], b;  // guest, sushi
int ans[MAXN];
int main() {
    cin >> n >> m;
    int top = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (top == 0 || t < a[top].first) {
            a[++top] = {t, i};
        }
    }
    n = top;
    for (int j = 1; j <= m; j++) {
        cin >> b.first;
        b.second = INF;
        auto it = lower_bound(a + 1, a + n + 1, b, greater<pii>());
        if (it == a + n + 1) {
            cout << -1 << '\n';
        } else {
            cout << it->second << '\n';
        }
    }
    return 0;
}
