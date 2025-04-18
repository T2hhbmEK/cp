#include <bits/stdc++.h>
using namespace std;
#define N 15
int n, m, mp[N][N], bld[N][N], ans[N][N], si, sj, ti, tj;

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

int bfs() {
    _push(si, sj);
    bld[si][sj] = 6;
    ans[si][sj] = 0;
    while (!qi.empty()) {
        int i, j;
        _pop(i, j);
        for (int k = 0; k < 4; ++k) {
            int i1 = i + di[k];
            int j1 = j + dj[k];
            if (mp[i1][j1] > 0) {
                int x;
                x = bld[i][j] - 1;
                if (x >= 1 && mp[i1][j1] == 4) {
                    x = 6;
                }
                if (x > bld[i1][j1]) {
                    _push(i1, j1);
                    bld[i1][j1] = x;
                    ans[i1][j1] = ans[i][j] + 1;
                    if (mp[i1][j1] == 3) {
                        return ans[i1][j1];
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &mp[i][j]);
            if (mp[i][j] == 2) {
                si = i;
                sj = j;  // start
            } else if (mp[i][j] == 3) {
                ti = i;
                tj = j;  // target
            } else if (mp[i][j] == 4) {
                // mice
            }
        }
    }
    cout << bfs() << endl;
    return 0;
}