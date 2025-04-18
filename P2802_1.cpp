#include <bits/stdc++.h>
using namespace std;
#define N 15
#define N2 105
typedef struct {
    int i;
    int j;
} P;
int n, m, mp[N][N], bld[N][N], wlk[N][N], ij2l[N][N], mice_cnt;
P s, t, m2ij[N2];
int d[N2][N2];  // dist of l1 to l2
int dp[N2][N2];
queue<int> qi, qj;
int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};
void _push(int i, int j) {
    qi.push(i);
    qj.push(j);
}
void _pop(int &i, int &j) {
    i = qi.front();
    qi.pop();
    j = qj.front();
    qj.pop();
}
void _empty() {
    while (!qi.empty()) {
        cout << "!!!" << endl;
        qi.pop();
        qj.pop();
    }
}
void bfs(int i, int j) {
    _empty();
    int l = i * 10 + j;  // for wlk
    _push(i, j);
    bld[i][j] = 6;
    while (!qi.empty()) {
        int i0, j0;
        _pop(i0, j0);
        for (int k = 0; k < 4; ++k) {
            int i1 = i0 + di[k];
            int j1 = j0 + dj[k];
            if (mp[i1][j1] > 0 && wlk[i1][j1] != l) {
                wlk[i1][j1] = l;
                bld[i1][j1] = bld[i0][j0] - 1;
                if (bld[i1][j1] >= 1 && mp[i1][j1] == 3) {
                    d[ij2l[i][j]][ij2l[i1][j1]] = 6 - bld[i1][j1];
                } else if (bld[i1][j1] >= 1 && mp[i1][j1] == 4) {
                    d[ij2l[i][j]][ij2l[i1][j1]] = 6 - bld[i1][j1];
                } else if (bld[i1][j1] > 1) {
                    _push(i1, j1);
                }
            }
        }
    }
}
bool wlkl[N2];
void dfsl(int l) {
    if (wlkl[l]) {
        return;
    }
    for (int ll = 1; ll <= mice_cnt+1;++ll) {
        if(!wlkl)
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &mp[i][j]);
            if (mp[i][j] == 2) {
                s = {i, j};  // start
            } else if (mp[i][j] == 3) {
                t = {i, j};  // target
            } else if (mp[i][j] == 4) {
                ij2l[i][j] = ++mice_cnt;
                m2ij[mice_cnt] = {i, j};
                // mice
            }
        }
    }
    ij2l[s.i][s.j] = 0;
    ij2l[t.i][t.j] = mice_cnt + 1;
    for (int l = 0; l <= mice_cnt; ++l) {
        int i = m2ij[l].i;
        int j = m2ij[l].j;
        if (mp[i][j] == 2 || mp[i][j] == 4) {
            bfs(i, j);
        }
    }
    bfsl(0);
    cout << -1 << endl;
    return 0;
}
