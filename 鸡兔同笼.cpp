#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i <= m; ++i) {
        int j = m - i;
        if (i * 2 + j * 4 == n) {
            cout << i << " " << j << "\n";
            return 0;
        }
    }
    cout << -1 << " " << -1 << "\n";
    return 0;
}
