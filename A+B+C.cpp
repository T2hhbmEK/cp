#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
const int inf = 0x3f3f3f3f;  // 1061109567
const int maxn = 1e4 + 5;

int n, m;
int a[maxn];

int solve() {
    sort(a, a + n);
    int ans = inf;
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = a[i] + a[l] + a[r];
            if (sum == m) {
                return m;
            } else if (sum < m) {
                l++;
            } else {
                r--;
            }
            if (abs(sum - m) < abs(ans - m)) {
                ans = sum;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("abc.in", "r", stdin);
    freopen("abc.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = solve();
    cout << ans << endl;
    return 0;
}
