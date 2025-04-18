#include <bits/stdc++.h>
using namespace std;
#define N 1000'005
int n, a, b, bmax, t[N], ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a, &b);
        ++a;  // prevent 0
        t[b] = max(t[b], a);
        bmax = max(bmax, b);
    }
    a = 0;
    b = 1;
    while (b <= bmax) {
        if (t[b] - 1 >= a) {
            // printf("%d %d\n", t[b] - 1, b);
            ans++;
            a = b;
        }
        b++;
    }
    cout << ans << endl;
    return 0;
}