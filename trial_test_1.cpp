#include <bits/stdc++.h>
using namespace std;
int d, y, m, a, b, ans;
int main() {
    cin >> d >> y >> m >> a >> b;
    if (m >= 9) {
        --d;
    }
    ans = d + a - y;
    if (b >= 9) {
        ++ans;
    }
    if (ans <= 12) {
        cout << ans << endl;
    } else if (ans <= 15) {
        cout << "college" << endl;
    } else {
        cout << "graduate" << endl;
    }
    return 0;
}