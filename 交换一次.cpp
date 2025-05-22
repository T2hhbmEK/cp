#include <bits/stdc++.h>
using namespace std;

int a[4];
int n = 3;

int cat(int x, int y, int z) {
    // 1 <= a, b, c < 1000
    int s = z;
    int w = 1;
    while (w <= s) {
        w *= 10;
    }
    s += y * w;
    while (w <= s) {
        w *= 10;
    }
    s += x * w;
    return s;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int ans = cat(a[1], a[2], a[3]);
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            swap(a[i], a[j]);
            int x = cat(a[1], a[2], a[3]);
            if (x < ans) {
                ans = x;
            }
            swap(a[i], a[j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
