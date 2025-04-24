#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1005
using namespace std;

int n, m, d[maxn], c[maxn], ans = inf;
int a[maxn];

void dfs(int k) {
    if (k > n) {
        int s = 0;
        for (int i = 1; i <= n; i++) {
            int j = a[i];
            s += d[i] * c[j];
        }
        ans = min(ans, s);
    }
    for (int j = a[k - 1] + 1; j <= m; j++) {
        a[k] = j;
        dfs(k + 1);
    }
}

inline int randint(int a, int b) {
    return rand() % (b - a) + a;
}

int main() {
    srand(3);
    n = randint(1, 20);
    m = randint(n, 20);
    cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        d[i] = randint(1, 1000);
        cout << d[i] << " \n"[i == n];
    }
    for (int i = 1; i <= m; i++) {
        c[i] = randint(1, 100);
        cout << c[i] << " \n"[i == m];
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
