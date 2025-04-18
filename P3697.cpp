#include <bits/stdc++.h>
using namespace std;
#define MaxM 3005
typedef long long ll;
int n, m, k;
ll a, b, c;
ll t;
int s[MaxM];
int ans;
struct Item {
    // p: additional reachable stops if lhs is a new fast stop
    int lhs, len, p;
    // tl: time left after arriving at lhs as a fast stop
    ll tl;
    Item(int _lhs, int _len, ll _tl) : tl(_tl), lhs(_lhs), len(_len) {  // [lhs, rhs)
        p = tl < 0 ? 0 : 1 + tl / a;
        p = min(len, p);
    }
    Item nxt() const {
        return Item(lhs + p, len - p, tl - p * c);
    }
    bool operator<(const Item& y) const {
        return p == y.p ? tl < y.tl : p < y.p;
    }
    void prt() {
        printf("[%d,%d],tl=%lld,p=%d", lhs, lhs + len - 1, tl, p);
    }
};
priority_queue<Item> q;
int main() {
#ifndef ONLINE_JUDGE
    freopen("P3697.in", "r", stdin);
#endif
    cin >> n >> m >> k >> a >> b >> c >> t;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &s[i]);
    }
    ans = -1;  // s[1]
    for (int i = 1; i < m; ++i) {
        ll tl = t - (s[i] - s[1]) * b;  // at s[i]
        struct Item x(s[i], s[i + 1] - s[i], tl);
        // cout << "init ", x.prt(), cout << endl;
        ans += x.p;
        x = x.nxt();
        if (x.p > 0) {
            // cout << "push ", x.prt(), cout << endl;
            q.push(x);
        }
    }
    if ((s[m] - s[1]) * b <= t) ++ans;  // s[m]
    while (k > m && !q.empty()) {
        ans += q.top().p;
        auto x = q.top();
        q.pop();
        q.push(x.nxt());
        --k;
    }
    cout << ans << endl;
    return 0;
}