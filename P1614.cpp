#include <iostream>
#define maxn 4096
#define inf 0x3f3f3f3f
using namespace std;

int n, m, a[maxn], ans = inf;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    for (int i = 0, j = m; j <= n; i++, j++) {
        ans = min(ans, a[j] - a[i]);
    }
    cout << ans << endl;
    return 0;
}
