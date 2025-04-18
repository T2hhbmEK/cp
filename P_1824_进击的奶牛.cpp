#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int n, c, x[maxn];

bool check(int d) {
    int cnt = 1, last = x[1];
    for (int i = 2; i <= n; i++) {
        if (x[i] - last >= d) {
            cnt++;
            last = x[i];
        }
    }
    return cnt >= c;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    sort(x + 1, x + n + 1);
    int l = 0, r = x[n] - x[1];
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}
