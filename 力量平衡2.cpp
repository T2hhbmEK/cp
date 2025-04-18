#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200005], sum, x, y, xnum, ynum, ans;
bool cmp(int i, int j) {
    return i > j;
}
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
    sort(a + 1, a + n + 1, cmp);
    // for (int i = 1; i <= n; ++i) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    for (int i = 1; i <= n; ++i) {
        if (i <= ynum) {
            ans += abs(a[i] - y);
        } else {
            ans += abs(a[i] - x);
        }
    }
    cout << ans / 2;
    return 0;
}