#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int a[N], b[N];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    int aL = 0, aR = n - 1, bL = 0, bR = n - 1;
    while (aL <= aR && bL <= bR) {
        if (a[aR] > b[bR]) {
            ans++;
            aR--, bR--;
        } else if (a[aR] < b[bR]) {
            ans--;
            aL++, bR--;
        } else if (a[aL] > b[bL]) {
            ans++;
            aL++, bL++;
        } else if (a[aL] < b[bR]) {
            ans--;
            aL++, bR--;
        } else if (a[aL] == b[bR]) {
            aL++, bR--;
        }
    }
    cout << ans * 200;
    return 0;
}
