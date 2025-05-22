#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAXN = 5e3 + 5;

int g[MAXN][MAXN], n, m, q;

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (g[a][b]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
