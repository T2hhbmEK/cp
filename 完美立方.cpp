#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int n;

inline int cube(int x) {
    return x * x * x;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int a = 1; a <= n; ++a) {
        int a3 = cube(a);
        for (int b = 2; cube(b) * 3 < a3; ++b) {
            for (int c = b + 1; cube(b) + cube(c) * 2 < a3; ++c) {
                int d3 = cube(a) - cube(b) - cube(c);
                int d = round(cbrt(d3));
                if (cube(d) == d3) {
                    printf("Cube = %d, Tirple = (%d,%d,%d)\n", a, b, c, d);
                }
            }
        }
    }
    return 0;
}
