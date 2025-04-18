#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
ll ans, d, b, nd, nb, n, t;
int main() {
    cin >> n >> t;
    cin >> d >> b;
    if (d > t) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", &nd, &nb);
        if (nd > t) {
            break;
        }
        // cout << nd << " " << nb << endl;
        if (b >= nd - d) {
            ans += nd - d;
            nb += b - (nd - d);
        } else {
            ans += b;
        }
        // cout << nd << " " << nb << endl;
        d = nd;
        b = nb;
    }
    if (b >= t - d + 1) {
        ans += t - d + 1;
    } else {
        ans += b;
    }
    cout << ans << endl;
    return 0;
}