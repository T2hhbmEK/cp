#include <bits/stdc++.h>
#define int long long
#define maxn 1005
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

int n, m;
int d[maxn], c[maxn];
int f[maxn][maxn];  // f[i][j] min cost from 1 to i in j hours

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    memset(f, 0x3f, sizeof(f));
    memset(f[0], 0, sizeof(f[0]));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = f[i][j - 1];  // arrive at i before j
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + d[i] * c[j]);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
