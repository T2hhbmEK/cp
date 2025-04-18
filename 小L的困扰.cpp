#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; 5 * i <= n; i++) {
        ans += (n - 5 * i) / 2 + 1;
    }
    cout << ans;
    return 0;
}
