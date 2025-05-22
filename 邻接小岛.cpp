#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAXN = 1e3 + 5;
const int MAXM = 1e6 + 5;

struct Edge {
    int to, next;
} e[MAXM];
int n, m, head[MAXN], tot;

void add(int u, int v) {
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }
    int u, v, a;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        add(u, v);
    }
    cin >> a;
    for (int i = head[a]; i != -1; i = e[i].next) {
        cout << e[i].to << " ";
    }
    return 0;
}
