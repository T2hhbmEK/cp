#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 32;
constexpr int m = 7;
int n, b[maxn], ans[maxn];

int main() {
    cin >> n;
    for (int i = 1, a; i <= m; i++) cin >> a, b[a]++;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1, a; j <= m; j++) {
            cin >> a;
            if (b[a] > 0) cnt++;
        }
        ans[cnt]++;
    }
    for (int i = m; i >= 1; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}