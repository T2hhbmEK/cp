#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int k;
        cin >> k;
        bool cnt[10] = {};
        while (k--) {
            int a;
            cin >> a;
            cnt[a] = 1;
        }
        int t = 0;
        for (int i = 1; i <= 9; ++i) {
            t += cnt[i];
        }
        if (t == 9) {
            ans += 1;
        }
    }
    cout << ans;
    return 0;
}