#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10;
int n, m, x;
int a[MAXN];  // guest

void fnd(int x) {
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> x;
        fnd(x);
    }
    return 0;
}
