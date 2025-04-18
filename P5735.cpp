#include <bits/stdc++.h>
using namespace std;
double x[3], y[3], ans;
double sq(double x) {
    return x * x;
}
int main() {
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        ans += sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}