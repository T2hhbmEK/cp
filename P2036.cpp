#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 15
using namespace std;

int n, s[maxn], b[maxn], ans = inf;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i] >> b[i];
    for (int i = 1; i < (1 << n); i++) {
        int tot_s = 1, tot_b = 0;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                tot_s *= s[j];
                tot_b += b[j];
            }
        }
        ans = min(ans, abs(tot_s - tot_b));
    }
    cout << ans << endl;
    return 0;
}
