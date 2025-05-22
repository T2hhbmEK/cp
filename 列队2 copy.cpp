#include <bits/stdc++.h>
using namespace std;
long long n, a = 1000000, b = 1000000, x[1000005], y[1000005], i, j, k, c, d;
int main() {
#ifndef ONLINE_JUDGE
    freopen("line.in", "r", stdin);
    freopen("line.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    y[++k] = 1;
    for (i = 2; n > 1; i++) {
        if (!(x[i])) {
            for (j = 2 * i; j <= n; j += i) {
                x[j] = 1;
            }
            if (n % i == 0) {
                n /= i;
                y[++k] = i;
                while (n % i == 0) {
                    y[k] *= i;
                    n /= i;
                }
            }
        }
    }
    // for (int i = 1; i <= k; i++) {
    //     cout << y[i] << " ";
    // }
    // cout << endl;
    for (i = 1; i <= k; i++) {
        c = d = 1;
        for (j = 1; j < i; j++) {
            c *= y[j];
        }
        for (j = i; j <= k; j++) {
            d *= y[j];
        }
        if (b > d && c <= d) {
            a = c;
            b = d;
        }
    }
    cout << a << " " << b;
    return 0;
}
