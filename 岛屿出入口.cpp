#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAXN = 5e2 + 5;

int g[MAXN][MAXN], n, m, q;

int main() {
    cin >> n >> m >> q;
    int u, v, a, cnt_out, cnt_in;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        g[u][v] = 1;
    }
    while(q--) {
        cnt_in = cnt_out = 0;
        cin >> a;
        for (int i = 1; i <= n; i++) {
            if (g[i][a] == 1) {
                cnt_in++;
            }
            if (g[a][i] == 1) {
                cnt_out++;
            }
        }
        cout << cnt_out << " " << cnt_in << endl;
    }
    return 0;
}
