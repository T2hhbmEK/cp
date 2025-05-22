#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int x, a, y, b;
    cin >> x >> a >> y >> b;
    double z = 1.0 * (y * b - x * a) / (b - a);
    cout << fixed << setprecision(2) << z;
    return 0;
}