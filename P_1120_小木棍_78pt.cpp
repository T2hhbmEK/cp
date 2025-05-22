#include <bits/stdc++.h>
#define maxn 70
using namespace std;

int n, m, x, a[maxn], cnt[maxn], sum, d, ans;
map<int, int> mp;

void dfs(int u, int k, int p) {
    if (k == 0) {
        cout << d << endl;
        exit(0);
    }
    while (p <= m && cnt[p] == 0) p++;
    int lo = p, hi = m;
    if (u == d) {
        hi = min(hi, p);
    }
    for (int i = lo; i <= hi; i++) {
        for (int j = 1, w = a[i]; j <= cnt[i] && w <= u; j++, w += a[i]) {
            cnt[i] -= j;
            if (u == w) {
                dfs(d, k - 1, 1);
            } else {
                dfs(u - w, k, i + 1);
            }
            cnt[i] += j;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
        mp[x]++;
    }
    for (auto it = mp.rbegin(); it != mp.rend(); it++) {
        ++m;
        a[m] = it->first;
        cnt[m] = it->second;
    }
    for (d = a[1]; (d << 1) <= sum; d++) {
        if (sum % d == 0) {
            dfs(d, sum / d - 1, 1);
        }
    }
    cout << sum;
    return 0;
}
