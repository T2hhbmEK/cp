#include <bits/stdc++.h>
using namespace std;
#define N 710
int n, bL[N], bR[N], rL[N], rR[N], ans;
char s[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        s[i] = s[i + n] = c;
    }
    for (int i = 1; i <= 2 * n; ++i) {
        switch (s[i]) {
            case 'b':
                bL[i] = bL[i - 1] + 1;
                rL[i] = 0;
                break;
            case 'r':
                rL[i] = rL[i - 1] + 1;
                bL[i] = 0;
                break;
            default:  // 'w
                bL[i] = bL[i - 1] + 1;
                rL[i] = rL[i - 1] + 1;
                break;
        }
    }
    for (int i = 2 * n; i >= 1; --i) {
        switch (s[i]) {
            case 'b':
                bR[i] = bR[i + 1] + 1;
                rR[i] = 0;
                break;
            case 'r':
                rR[i] = rR[i + 1] + 1;
                bR[i] = 0;
                break;
            default:  // 'w
                bR[i] = bR[i + 1] + 1;
                rR[i] = rR[i + 1] + 1;
                break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int nLR = max(bL[n + i], rL[n + i]) + max(bR[i + 1], rR[i + 1]);
        ans = max(ans, nLR);
    }
    ans = min(ans, n);
    cout << ans;
    return 0;
}