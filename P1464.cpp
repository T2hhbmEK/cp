#include <bits/stdc++.h>
#define int long long
#define maxn 25
using namespace std;

int a, b, c, ans;
int dp[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if (vis[a][b][c]) return dp[a][b][c];
    vis[a][b][c] = 1;
    if (a < b && b < c)
        return dp[a][b][c] =
                   w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) +
                         w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

signed main() {
    cin >> a >> b >> c;
    while (a != -1 || b != -1 || c != -1) {
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
        cin >> a >> b >> c;
    }
    return 0;
}
