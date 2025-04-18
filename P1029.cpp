#include <bits/stdc++.h>
using namespace std;
#define N 100'005
int p[N], pn, cnt[N], x, y;
int pow(int x, int y) {
    int r = 1;
    while (y >= 1) {
        if (y % 2 == 1) {
            r *= x;
        }
        x *= x;
        y /= 2;
    }
    return r;
}
int main() {
    cin >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }
    y /= x;
    for (int i = 2; i <= y; ++i) {
        if (y % i == 0) {
            p[++pn] = i;
            while (y % i == 0) {
                y /= i;
                cnt[pn]++;
            }
        }
    }
    for (int i = 1; i <= pn; ++i) {
        // cout << p[i] << " " << cnt[i] << endl;
        x *= pow(p[i], cnt[i]);
    }
    // cout << x << endl;
    int ans = pow(2, pn);
    cout << ans << endl;
    return 0;
}