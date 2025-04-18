#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct node {
    int i, b, a;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n;
    vector<int> a(n), b(n * 2);
    vector<node> s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 2 * n; i++) {
        cin >> b[i];
    }
    cin >> q;
    for (int i = 0; i < n; i++) {
        s[i].b = b[i] + b[2 * n - 1 - i];
        s[i].i = i;
    }
    sort(a.begin(), a.end());
    sort(s.begin(), s.end(), [](node x, node y) { return x.b < y.b; });
    for (int i = 0; i < n; i++) {
        s[i].a = a[i];
    }
    sort(s.begin(), s.end(), [](node x, node y) { return x.i < y.i; });
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += s[i].b * s[i].a;
    }
    cout << ans << endl;
    if (q == 1) {
        for (int i = 0; i < n; i++) {
            cout << s[i].a << " ";
        }
    }
}
