#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int n, c, m, e;
struct Stu {
    int id, sum, sum_cm, max_cm;
} a[N];
int ans[N];

bool cmp(const Stu& x, const Stu& y) {
    if (x.sum != y.sum) return x.sum > y.sum;
    if (x.sum_cm != y.sum_cm) return x.sum_cm > y.sum_cm;
    return x.max_cm > y.max_cm;
}

bool eq(const Stu& x, const Stu& y) {
    return x.sum == y.sum && x.sum_cm == y.sum_cm && x.max_cm == y.max_cm;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c >> m >> e;
        a[i].id = i;
        a[i].sum = c + m + e;
        a[i].sum_cm = c + m;
        a[i].max_cm = max(c, m);
    }
    sort(a + 1, a + 1 + n, cmp);
    ans[a[1].id] = 1;
    for (int i = 2; i <= n; i++) {
        if (eq(a[i], a[i - 1])) {
            ans[a[i].id] = ans[a[i - 1].id];
        } else {
            ans[a[i].id] = i;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}
