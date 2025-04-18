#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> b(4001, 0);
    int maxa = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        b[a] += 1;
        maxa = max(maxa, a);
    }
    int ans = 0, cnt = 0;
    for (int h = 2; h <= maxa * 2; h++) {
        int ans_ = 0;
        for (int i = 1; i <= h - i; i++) {
            if (h - i == i) {
                ans_ += b[i] / 2;
            } else {
                ans_ += min(b[i], b[h - i]);
            }
        }
        // cout << h << " " << ans_ << endl;
        if (ans_ > ans) {
            ans = ans_;
            cnt = 1;
        } else if (ans_ == ans) {
            cnt += 1;
        }
    }
    cout << ans << ' ' << cnt << endl;
    return 0;
}
