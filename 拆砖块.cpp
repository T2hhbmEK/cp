#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e7 + 5;
const int INF = 0x3f3f3f3f;
int n, k;
ll ans = INF;
int a[N];
ll pre[N];    // prefix sum
list<int> q;  // monotonic non-decreasing queue

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int r = 1; r <= n; r++) {
        int l = r - k + 1;
        while (!q.empty() && q.front() < l) q.pop_front();
        while (!q.empty() && a[q.back()] > a[r]) q.pop_back();
        q.push_back(r);
        if (l < 1) continue;
        ll sum = pre[r] - pre[l - 1] - (ll)a[q.front()] * k;
        ans = min(ans, sum);
    }
    cout << ans;
    return 0;
}
