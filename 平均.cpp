#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
signed main() {
    freopen("average.in", "r", stdin);
    freopen("average.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int c1 = n / m;
    int ans1 = (n - c1 * m) * b;
    int c2 = c1 + 1;
    int ans2 = (c2 * m - n) * a;
    cout << min(ans1, ans2) << endl;
    return 0;
}
