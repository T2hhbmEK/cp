#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6 + 5;
int n, p, a[N], sub[N], x, y, z, amin = 1e9;
int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        sub[i] = a[i] - a[i - 1];
    }
    while (p--) {
        cin >> x >> y >> z;
        sub[x] += z;
        sub[y + 1] -= z;
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1] + sub[i];
        amin = min(amin, a[i]);
    }
    cout << amin;
    return 0;
}