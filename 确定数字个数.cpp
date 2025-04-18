#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
int a[maxn];
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (m--) {
        int x;
        cin >> x;
        int l = lower_bound(a + 1, a + 1 + n, x) - a;
        int r = upper_bound(a + 1, a + 1 + n, x) - a;
        cout << r - l << ' ';
    }
    return 0;
}
