#include <bits/stdc++.h>
using namespace std;
struct proc {
    int i, t, l, w;
    bool operator<(const proc& y) const {
        return w == y.w ? t > y.t : w < y.w;
    }
};
void p(const proc& x) {
    printf("%d %d %d %d\n", x.i, x.t, x.l, x.w);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("P2278.in", "r", stdin);
#endif
    int i, t, l, w;
    priority_queue<proc> q;
    int now = 0;
    while (scanf("%d%d%d%d", &i, &t, &l, &w) > 0) {
        while (!q.empty() && now + q.top().l <= t) {
            // run
            now = now + q.top().l;
            printf("%d %d\n", q.top().i, now);
            q.pop();
            now = max(now, q.top().t);
        }
        if (!q.empty() && w > q.top().w && now + q.top().l > t) {
            // run && interupt
            proc x = q.top();
            x.l -= t - now;
            now = t;
            q.pop();
            q.push(x);
        }
        q.push({i, t, l, w});
        now = max(now, q.top().t);
    }
    while (!q.empty()) {
        now = now + q.top().l;
        printf("%d %d\n", q.top().i, now);
        q.pop();
        now = max(now, q.top().t);
    }
    return 0;
}