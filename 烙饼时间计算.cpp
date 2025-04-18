#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int t;

int solve() {
    if (t == 1) return 6;
    return t * 3;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    cout << solve();
    return 0;
}
