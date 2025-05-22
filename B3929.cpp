#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a, n, x, f[N + 7];
int g[N + 7];

void init() {
    for (int i = ceil(sqrt(a)); i * i <= N; i++) {
        int i2 = i * i;
        if (!f[i2]) {
            for (int j = i2; j <= N; j += i2) {
                f[j] = 1;
            }
        }
    }
    int j = -1;
    for (int i = N; i >= 1; i--) {
        if (f[i]) {
            j = i;
        }
        g[i] = j;
    }
}

void solve() {
    cin >> x;
    if (f[x]) {
        cout << "lucky";
    } else {
        cout << g[x];
    }
    cout << '\n';
}

int main() {
    cin >> a >> n;
    init();
    while (n--) {
        solve();
    }
    return 0;
}
