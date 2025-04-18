#include <bits/stdc++.h>
using namespace std;
#define N 1005
int main() {
    int n;
    cin >> n;
    int l = 11;
    int r = -1;
    float ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        l = min(l, x);
        r = max(r, x);
        ans += x;
    }
    ans = (ans - l - r) / (n - 2);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}