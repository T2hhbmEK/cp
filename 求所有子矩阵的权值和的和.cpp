#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int

uint n, m;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    uint sum = 0, a;
    for (uint i = 1; i <= n; i++) {
        for (uint j = 1; j <= m; j++) {
            cin >> a;
            sum += a * i * j * (n - i + 1) * (m - j + 1);
        }
    }
    cout << sum;
    return 0;
}