#include <iostream>
#define maxn 128
using namespace std;
int n, m, k, a[maxn][maxn], ans;
int main() {
    cin >> n >> m >> k;
    while (m--) {
        int x, y;
        cin >> x >> y;
        for (int i = x - 2; i <= x + 2; i++) {
            for (int j = y - 2; j <= y + 2; j++) {
                if (i >= 1 && i <= n && j >= 1 && j <= n &&
                    abs(i - x) + abs(j - y) <= 2) {
                    a[i][j] = 1;
                }
            }
        }
    }
    while (k--) {
        int x, y;
        cin >> x >> y;
        for (int i = x - 2; i <= x + 2; i++) {
            for (int j = y - 2; j <= y + 2; j++) {
                if (i >= 1 && i <= n && j >= 1 && j <= n) {
                    a[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
