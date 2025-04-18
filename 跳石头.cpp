#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 5;

int L, n, m, d[maxn];

bool check(int x) {
    int cnt = 0, last = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (d[i] - last < x) {
            cnt++;
        } else {
            last = d[i];
        }
    }
    return cnt <= m;
}

int main() {
    cin >> L >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    d[n + 1] = L;
    int l = 0, r = L;
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
