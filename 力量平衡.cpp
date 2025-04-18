#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200005], sum, x, y, xnum, ynum, ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    x = sum / n;
    y = x + 1;
    ynum = sum - x * n;
    // cout << x << " " << y << " " << ynum << endl;
    // for (int i = 1; i <= n; ++i) {
    //     if (a[i] > y) {
    //         if (ynum) {
    //             ans += a[i] - y;
    //             ynum -= 1;
    //         } else {
    //             ans += a[i] - x;
    //         }
    //     }
    // }
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= y && ynum) {
            ans += a[i] - y;
            ynum -= 1;
        } else {
            ans += a[i] - x;
        }
    }
    cout << ans / 2;
    return 0;
}