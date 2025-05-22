#include <bits/stdc++.h>
using namespace std;
#define int long long
#define OPEN true
#define CLOSE false

struct Number {
    int a, b;  // a / b
};

struct Interval {
    Number l, r;
    bool lo, ro;  // open/close interval
};

bool cmp(Number x, Number y) {  // x < y
    return x.a * y.b < y.a * x.b;
}

bool cmp(Interval x, Interval y) {  // x < y
    if (cmp(x.r, y.r) == cmp(y.r, x.r)) {
        assert(!cmp(x.r, y.r) && !cmp(y.r, x.r));
        if (x.ro != y.ro) return x.ro;
        return cmp(x.l, y.l);
    }
    return cmp(x.r, y.r);
}

bool chkL(Interval t, int p) {
    Number np = {p, 1};
    if (t.lo) {                // (
        return cmp(t.l, np);   // l < p
    } else {                   // [
        return !cmp(np, t.l);  // l <= p
    }
}

bool chkR(Interval t, int p) {
    Number np = {p, 1};
    if (t.ro) {                // )
        return cmp(np, t.r);   // p < r
    } else {                   // ]
        return !cmp(t.r, np);  // p <= r
    }
}

bool chk(Interval t, int p) {
    return chkL(t, p) && chkR(t, p);
}

void solve() {
    int n, m, L, V;
    cin >> n >> m >> L >> V;
    Number nL = {L, 1};
    vector<Interval> s;
    for (int i = 0; i < n; i++) {
        int d, v, a;
        cin >> d >> v >> a;
        Interval t;
        bool flag = true;
        if (a > 0) {
            if (v >= V) {  // [d, L] (d, L]
                t.l = {d, 1};
                t.lo = (v == V);
                t.r = {L, 1};
                t.ro = CLOSE;
            } else {  // (d+(V^2-v^2)/2a, L]
                t.l = {2 * a * d + V * V - v * v, 2 * a};
                t.lo = OPEN;
                t.r = {L, 1};
                t.ro = CLOSE;
                if (!cmp(t.l, t.r)) flag = false;
            }
        } else if (a == 0) {
            if (v > V) {  // [d, L]
                t.l = {d, 1};
                t.lo = CLOSE;
                t.r = {L, 1};
                t.ro = CLOSE;
            } else {
                flag = false;
            }
        } else {  // a < 0
            if (v <= V) {
                flag = false;
            } else {  // [d, d+(v^2-V^2)/2a)
                t.l = {d, 1};
                t.lo = CLOSE;
                t.r = {2 * a * d + v * v - V * V, 2 * a};
                t.ro = OPEN;
                if (!cmp(t.r, nL)) {  // [d, L]
                    t.r = nL;
                    t.ro = CLOSE;
                }
            }
        }
        if (flag) s.push_back(t);
    }
    sort(s.begin(), s.end());
    vector<int> p(m);
    auto it = s.begin();
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
