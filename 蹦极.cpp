#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("bungee.in", "r", stdin);
    freopen("bungee.out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0);
    double h, x;
    cin >> h >> x;
    x *= 0.01;
    int n = 0;
    while (h >= 2) {
        h *= x;
        ++n;
    }
    if (h > 1) ++n;
    cout << n;
    return 0;
}
