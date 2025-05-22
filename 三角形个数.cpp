#include <bits/stdc++.h>
using namespace std;
// #define int long long

int n, sum;

void solve1() {  // O(n^2)
    for (int i = 1; i <= n; i++) {
        for (int j = i, k = n - i - j; j <= k; j++, k--) {
            // i <= j <= k
            if (i + j > k && i + k > j) sum++;
        }
    }
}

void solve2() {  // O(n)
    for (int i = 1; i <= n; i++) {
        int a = max(i, (n - 2 * i + 2) / 2);
        int b = (n - i) / 2;
        sum += max(b - a + 1, 0);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    solve2();
    cout << sum;
    return 0;
}
