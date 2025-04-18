#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
int h[maxn];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int t = 0;
    for (int i = 1; i <= n; i++) {
        t += h[i] / 5 * 3;
        h[i] %= 5;
        while (h[i] > 0) {
            t++;
            h[i] -= t % 3 ? 1 : 3;
        }
    }
    cout << t << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}
