#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
int a[maxn];
int s[maxn], top;
signed main() {
    freopen("grouping.in", "r", stdin);
    freopen("grouping.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        int d = a[i] - a[i - 1];
        if (d > x) {
            s[++top] = d / x;
            ans++;
        }
    }
    sort(s + 1, s + 1 + top);
    for (int i = 1; i <= top && k >= s[i]; i++) {
        k -= s[i];
        ans--;
    }
    cout << ans << endl;
    return 0;
}
