#include <bits/stdc++.h>  //万能头文件，freopen也在其中
using namespace std;
#define ll long long
const int maxn = 105;
int n, a[maxn], b[maxn], ans;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) {
        // if (a[i] > b[i]) {
        //     ans += (a[i] - b[i]) / 10;
        // } else if (b[i] > a[i]) {
        //     ans -= (b[i] - a[i]) / 10;
        // }
        // 和上面的代码等价
        ans += (a[i] - b[i]) / 10;
    }
    cout << ans;
    return 0;
}
