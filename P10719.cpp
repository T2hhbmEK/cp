#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int INF = 0x3f3f3f3f;
int n, m, k, a[N][N], ans = INF;
string s;

int f(int t, int l, int b, int r) {
    return a[b][r] - a[t - 1][r] - a[b][l - 1] + a[t - 1][l - 1];
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= m; j++) {
            a[i][j] = s[j - 1] - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i][j - 1];
        }
        for (int j = 1; j <= m; j++) {
            a[i][j] += a[i - 1][j];
        }
    }
    for (int t = 1; t <= n; t++) {
        for (int l = 1; l <= m; l++) {
            for (int b = t; b <= n; b++) {
                int L = l, R = m;
                while (L < R) {
                    int mid = (L + R) >> 1;
                    int sum = f(t, l, b, mid);
                    if (sum >= k) {
                        R = mid;
                    } else {
                        L = mid + 1;
                    }
                }
                if (f(t, l, b, R) >= k) {
                    int area = (b - t + 1) * (R - l + 1);
                    ans = min(ans, area);
                }
            }
        }
    }
    if (ans == INF) {
        cout << 0;
    } else {
        cout << ans;
    }
    return 0;
}
