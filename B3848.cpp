#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, a[N], x, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> x;
    for (int i = 1; i <= n; i++) {
        if (a[i] <= x) {
            ans++;
            x -= a[i];
        }
    }
    cout << ans;
    return 0;
}
