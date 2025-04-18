#include <bits/stdc++.h>
using namespace std;

const int N = 505;
struct Node {
    int T, R;
} s[N];
int n;
bool f[N];

bool cmp(const Node &x, const Node &y) {
    if (x.R != y.R) return x.R > y.R;
    return x.T < y.T;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i].T;
    for (int i = 1; i <= n; i++) cin >> s[i].R;
    sort(s + 1, s + 1 + n, cmp);
    int ans = 0;
    int m = n;
    while (m > 0) {
        for (int i = 1; i <= n; i++) {
            if (!f[i] && s[i].T >= m) {
                f[i] = 1;
                ans += s[i].R;
                break;
            }
        }
        m--;
    }
    cout << ans;
    return 0;
}
