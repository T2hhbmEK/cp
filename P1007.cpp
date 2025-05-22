#include <bits/stdc++.h>
using namespace std;

int l, n;
int a, ans1, ans2;

int main() {
    cin >> l >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        ans1 = max(ans1, min(a - 0, l + 1 - a));
        ans2 = max(ans2, max(a - 0, l + 1 - a));
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}
