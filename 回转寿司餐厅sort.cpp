#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAXN = 2e5 + 10;
int n, m;
pii a[MAXN];  // guest
pii b[MAXN];  // sushi
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
    for (int i = 1; i <= m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b + 1, b + m + 1, greater<pii>());
    for (int i = 1, j = 1; j <= m;) {
        if (a[i].first <= b[j].first) {
            ans[b[j].second] = a[i].second;
            j++;
        } else if (i < n) {
            i++;
        } else {
            ans[b[j].second] = -1;
            j++;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
