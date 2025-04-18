#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAXN = 5e4 + 5;
const int MAXM = 2e5 + 5;

struct Edge {
    int to, next;
} e[MAXM];
int n, m, q, head[MAXN], tot;
int ans[MAXN], top;

void add(int u, int v) {
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    while (q--) {
        int x;
        top = 0;
        cin >> x;
        for (int i = head[x]; i != -1; i = e[i].next) {
            ans[++top] = e[i].to;
        }
        sort(ans + 1, ans + top + 1);
        for (int i = 1; i <= top; i++) {
            cout << ans[i] << " ";
        }
        if (top == 0) {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}
