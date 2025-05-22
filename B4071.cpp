#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1005;
int n, m;
struct Material {
    int p, c;
} a[N];
vector<int> s[N];
int ans = LONG_LONG_MAX;
bool f[N];

bool cmp(const Material &x, const Material &y) {
    return x.c > y.c;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].p >> a[i].c;
    }
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        s[a[i].p].push_back(i);
    }
    int wmax = 0;
    for (int i = 1; i <= n; i++) {
        wmax = max(wmax, (int)s[i].size());
    }
    for (int k = wmax; k >= 0; k--) {
        int cnt = s[1].size();
        int sum = 0;
        memset(f, 0, sizeof(f));
        for (int i = 2; i <= n; i++) {
            for (int j = k; j < (int)s[i].size(); j++) {
                f[s[i][j]] = 1;
                sum += a[s[i][j]].c;
                cnt++;
            }
        }
        for (int i = m; i >= 1 && cnt <= k; i--) {
            if (f[i] || a[i].p == 1) continue;
            cnt++;
            sum += a[i].c;
            f[i] = 1;
        }
        if (cnt > k) ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}
