#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int r, c, k, ans;
char a[maxn][maxn];
int dpR[maxn][maxn], dpC[maxn][maxn];

int main() {
    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
            if (a[i][j] == '#') {
                dpR[i][j] = dpC[i][j] = 0;
            } else {
                dpR[i][j] = dpR[i][j - 1] + 1;
                dpC[i][j] = dpC[i - 1][j] + 1;
                if (dpR[i][j] >= k) ans++;
                if (k > 1 && dpC[i][j] >= k) ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
