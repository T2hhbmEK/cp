#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int n, q;

struct stu {
    int i, a;
} a[maxn], b;

bool cmp(stu x, stu y) { return x.a < y.a; }

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a;
        a[i].i = i;
    }
    stable_sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= q; i++) {
        cin >> b.a;
        int l = lower_bound(a + 1, a + 1 + n, b, cmp) - a;
        cout << (a[l].a == b.a ? a[l].i : -1) << '\n';
    }
    return 0;
}
