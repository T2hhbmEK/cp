#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    double ans = pow(a, b);
    if (ans > 1e9) {
        cout << -1 << endl;
    } else {
        cout << (int)round(ans) << endl;
    }
    return 0;
}
