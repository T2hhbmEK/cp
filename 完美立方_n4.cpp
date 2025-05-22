#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int n;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int a = 1; a <= n; ++a) {
        for (int b = 2; b < a; ++b) {
            for (int c = b + 1; c < a; ++c) {
                for (int d = c + 1; d < a; ++d) {
                    if (a * a * a == b * b * b + c * c * c + d * d * d) {
                        printf("Cube = %d, Tirple = (%d,%d,%d)\n", a, b, c, d);
                    }
                }
            }
        }
    }
    return 0;
}
