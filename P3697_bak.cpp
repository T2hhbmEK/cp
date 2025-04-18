#include <bits/stdc++.h>
using namespace std;
#define N 3005
typedef long long ll;
int n, m, k;
ll a, b, c;
ll t;
int s[N];
ll ans;
struct unreachable_interval {
    int lhs, rhs;
    int potential;
    ll potential_cost;
    bool operator<(const unreachable_interval& x) const {
        return potential < x.potential;
    }
    void p() {
        printf("[%d,%d],c=%lld,p=%d", lhs, rhs, potential_cost, potential);
    }
};
priority_queue<unreachable_interval> q;
int main() {
#ifndef ONLINE_JUDGE
    freopen("P3697.in", "r", stdin);
#endif
    cin >> n >> m >> k >> a >> b >> c >> t;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &s[i]);
    }
    int last_reachable = s[1] + t / a;
    ans += last_reachable - 1;  // 1 excluded
    for (int i = 2; i <= m; ++i) {
        if ((s[i] - s[1]) * b > t) break;  // out of reach
        if (s[i] <= last_reachable + 1) {  // all reachable
        } else {
            unreachable_interval x;
            x.lhs = last_reachable + 1;
            x.rhs = s[i] - 1;
            //                 ultra                fast
            x.potential_cost = (s[i - 1] - 1) * b + (x.lhs - s[i - 1]) * c;  // potential cost to reach lhs
            x.potential = (t - x.potential_cost) / a + 1;
            x.potential = min(x.rhs - x.lhs + 1, x.potential);
            x.p(), cout << endl;
            q.push(x);
        }
        last_reachable = s[i] + (t - s[i] * b) / a;
        ans += last_reachable - s[i] + 1;
    }
    // cout << ans << endl;
    while (!q.empty() && k > m) {
        unreachable_interval x = q.top();
        q.pop();
        ans += x.potential;
        x.lhs = x.lhs + x.potential;
        //                  fast
        x.potential_cost += x.potential * c;
        if (x.lhs <= x.rhs && x.potential_cost <= t) {
            x.potential = (t - x.potential_cost) / a + 1;
            x.potential = min(x.rhs - x.lhs + 1, x.potential);
            q.push(x);
        }
        --k;
    }
    cout << ans << endl;
    return 0;
}