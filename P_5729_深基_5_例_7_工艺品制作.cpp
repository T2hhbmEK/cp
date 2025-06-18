#include <bits/stdc++.h>
#define maxn 30
using namespace std;

int w, x, h, q, ans;
int a[maxn][maxn][maxn];

int main() {
    cin >> w >> x >> h >> q;
    while (q--) {
        int x[3][4];
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= 3; j++) cin >> x[i][j];
        }
        for (int i = x[1][1]; i <= x[2][1]; i++) {
            for (int j = x[1][2]; j <= x[2][2]; j++) {
                for (int k = x[1][3]; k <= x[2][3]; k++) {
                    a[i][j][k] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= h; k++) {
                if (a[i][j][k] == 0) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
