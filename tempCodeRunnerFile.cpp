#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int n;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int n3 = n * n * n;
    for (int b = 1; b * b * b < n3; ++b) {
        for (int c = b; b * b * b + c * c * c < n3; ++c) {
            for (int d = c; b * b * b + c * c * c + d * d * d <= n3; ++d) {
                int a3 = b * b * b + c * c * c + d * d * d;
                int a = cbrt(a3);
                if (a * a * a == a3) {
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                }
            }
        }
    }
    return 0;
}
