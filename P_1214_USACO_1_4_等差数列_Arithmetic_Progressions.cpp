#include <bits/stdc++.h>
using namespace std;
const int N = 250 * 250 * 2 + 5;
const int M = N / 2 + 1;
int n, m, amax, s[N], bmax, cnt, acnt;
bool t[N];
vector<int> ans[M];
bool test(int a, int b) {
    for (int i = 0; i < n; ++i, a += b) {
        if (!t[a]) {
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    amax = m * m * 2;
    for (int p = 0; p <= m; ++p) {
        for (int q = p; q <= m; ++q) {
            int x = p * p + q * q;
            if (!t[x]) {
                t[x] = true;
                s[cnt++] = x;
            }
        }
    }
    sort(s, s + cnt);
    for (int i = 0; i < cnt; ++i) {
        for (int j = i + 1; j < cnt; ++j) {
            int a = s[i], b = s[j] - s[i];
            if (a + b * (n - 1) > amax) break;
            if (test(a, b)) {
                acnt += 1;
                bmax = max(bmax, b);
                ans[b].push_back(a);
            }
        }
    }
    assert(acnt <= 1E4);
    if (bmax == 0) {
        cout << "NONE";
    } else {
        for (int b = 1; b <= bmax; ++b) {
            for (int a : ans[b]) {
                cout << a << " " << b << "\n";
            }
        }
    }
    return 0;
}