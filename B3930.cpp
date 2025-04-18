#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
int n, a[N], ans;
bool f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j = 30; j >= 0; j--) {
        int mask = 1 << j;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (!f[i] && (a[i] & mask)) {
                cnt++;
            }
        }
        if (cnt < 2) continue;
        for (int i = 1; i <= n; i++) {
            if (!f[i] && !(a[i] & mask)) {
                f[i] = 1;
            }
        }
        ans |= mask;
    }
    cout << ans;
    return 0;
}
