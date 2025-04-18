#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = INF;
    if (a == c) swap(b, c);
    if (b == c) swap(a, c);
    if (a == b) {
        if (2 * a > c) {
            ans = 0;
        } else {
            ans = min(ans, c - (2 * a - 1));
        }
    }
    // a -> b || b -> a
    if (2 * b > c || 2 * a > c) {
        ans = min(ans, abs(a - b));
    }
    // a -> c || c -> a
    if (2 * c > b || 2 * a > b) {
        ans = min(ans, abs(a - c));
    }
    // b -> c || c -> b
    if (2 * c > a || 2 * b > a) {
        ans = min(ans, abs(b - c));
    }
    cout << ans;
    return 0;
}
