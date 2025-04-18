#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
const double inf = 1e10;
const int maxn = 1e5 + 5;

int n, p, a[maxn], b[maxn];

bool check(double x) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += max(0.0, a[i] * x - b[i]);
    }
    return sum <= p * x;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> p;
    long long sum_a = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> b[i];
        sum_a += a[i];
    }
    if (sum_a <= p) {
        cout << -1 << endl;
        return 0;
    }
    double l = 0, r = inf;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(4) << l << endl;
}
