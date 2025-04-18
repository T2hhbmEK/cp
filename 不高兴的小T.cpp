#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int a, b, n = 7, maxi, maxv;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        a += b;
        if (a > 8 && a > maxv) {
            maxi = i;
            maxv = a;
        }
    }
    cout << maxi;
    return 0;
}
