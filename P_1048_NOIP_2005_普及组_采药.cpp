#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXT = 1005;
int T, M;
int t[MAXN], v[MAXN];
int f[MAXN][MAXT];

int main() {
    cin >> T >> M;
    for (int i = 1; i <= M; i++) cin >> t[i] >> v[i];
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j <= T; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= t[i]) f[i][j] = max(f[i][j], f[i - 1][j - t[i]] + v[i]);
        }
    }
    cout << f[M][T];
    return 0;
}
