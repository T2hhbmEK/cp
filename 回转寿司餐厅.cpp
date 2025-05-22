#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10;
int n, m, x;
int a[MAXN];  // guest
pii b[MAXN];  // sushi {taste, idx}
int ans[MAXN];

int main() {
    cin >> n >> m;
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b + 1, b + m + 1, greater<pii>());
    for (int i = 1, j = 1; i <= n && j <= m; i++) {
        while (j <= m && a[i] <= b[j].first) {
            ans[b[j].second] = i;
            j++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
