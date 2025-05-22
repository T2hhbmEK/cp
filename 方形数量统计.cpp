#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m, ans[2];

int combi(int a, int b) {
    if (b + b > a) b = a - b;
    int ans = 1;
    for (int i = 0; i < b; i++) {
        ans *= a - i;
    }
    for (int i = 1; i <= b; i++) {
        ans /= i;
    }
    return ans;
}

void solve1() {
    ans[1] = ((n + 1) * n / 2) * ((m + 1) * m / 2);
    for (int i = 1; i <= n && i <= m; i++) {  // O(n)
        ans[0] += (n - i + 1) * (m - i + 1);
    }
    ans[1] -= ans[0];
}

void sovle2() {
    for (int h = 1; h <= n; h++) {
        for (int w = 1; w <= m; w++) {
            ans[h != w] += (n - h + 1) * (m - w + 1);
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    solve1();
    for (int i = 0; i < 2; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
