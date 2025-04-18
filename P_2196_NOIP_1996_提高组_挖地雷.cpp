#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
int n;
int a[MAXN];
vector<int> fa[MAXN];
int f[MAXN];
int tr[MAXN];

void dfs(int u) {
    if (tr[u]) dfs(tr[u]);
    cout << u << " ";
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int t;
            cin >> t;
            if (t) fa[j].push_back(i);
        }
    }
    int max_val = 0, max_idx = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = a[i];
        for (int j : fa[i]) {
            if (f[j] + a[i] > f[i]) {
                f[i] = f[j] + a[i];
                tr[i] = j;
            }
        }
        if (f[i] > max_val) {
            max_val = f[i];
            max_idx = i;
        }
    }
    dfs(max_idx);
    cout << endl << max_val << endl;
    return 0;
}
