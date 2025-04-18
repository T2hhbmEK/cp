#include <bits/stdc++.h>
using namespace std;
double w0, w;
int m;

double f(double k) {
    double ans = 0, r = 1;
    for (int i = 1; i <= m; ++i) {
        r *= (1 + k);
        ans += w / r;
    }
    // cout << k << " " << ans << endl;
    return ans;
}

int main() {
    cin >> w0 >> w >> m;
    double i = 0, j = 3.0001;
    while (j - i > 0.0001) {  // [i, j)
        double k = (i + j) / 2;
        if (f(k) < w0) {
            j = k;
        } else {
            i = k;
        }
    }
    cout << fixed << setprecision(1) << round(i * 1000) / 10 << endl;
    return 0;
}