#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAXN = 5e4 + 5;
const int MAXM = 1e5 + 5;

struct Edge {
    int u, v;
} e[MAXM];
bool vis[MAXN];
int n, m, q;

void f(int a, int b) {
    for (int i = 1; i <= m; i++) {
        if (e[i].u == a && e[i].v == b || e[i].u == b && e[i].v == a) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v;
    }
    for (int i = 1; i <= q; ++i) {
        int a, b;
        cin >> a >> b;
        f(a, b);
    }
    return 0;
}
