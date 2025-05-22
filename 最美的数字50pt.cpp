#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    long long x = 1;
    for (int i = 2; i <= n; i++) x *= 10;
    long long ans = x;
    while (ans % t != 0) ans++;
    if (ans >= x * 10) {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}
