#include <bits/stdc++.h>
using namespace std;
#define N 15
typedef long long ll;
ll t, ac, dc, vc, am, dm, vm, x, y, k, ans[N];

int main() {
    cin >> t;
    for (ll i = 1; i <= t; ++i) {
        cin >> ac >> dc >> vc;
        cin >> am >> dm >> vm;
        cin >> x >> y >> k;
        for (ll j = 0; j <= k && ans[i] == 0; ++j) {
            ll ac_ = ac + x * j;
            ll dc_ = dc + y * (k - j);
            ll cnt = (dc_ - 1) / am + 1;
            if (vc < vm) {
                cnt--;
            }
            if (cnt >= 0 && ac_ * cnt >= dm) {
                ans[i] = 1;
            }
        }
    }
    for (ll i = 1; i <= t; ++i) {
        cout << ans[i] << endl;
    }
}