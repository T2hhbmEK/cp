#include <bits/stdc++.h>
using namespace std;

char a[105][105];
char p[4][5] = {
    "0000",
    "0110",
    "0110",
    "0000",
};
int n, m;

bool check(int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[x + i][y + j] != p[i][j]) return false;
        }
    }
    return true;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < m - 3; j++) {
            if (check(i, j)) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
