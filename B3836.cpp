#include <bits/stdc++.h>
using namespace std;

int x, y, z, n, m, ans;
int main() {
    cin >> x >> y >> z >> n >> m;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m - i; j++) {
            if (x * i + y * j + 1.0 * (m - i - j) / z == n) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
