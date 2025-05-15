#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int n;
char a[maxn][maxn], f[maxn][maxn];
string p = "yizhong";
int dr[8][2]{
    {-1, -1}, {-1, 0}, {-1, 1},  //
    {0, -1},  {0, 1},            //
    {1, -1},  {1, 0},  {1, 1},   //
};

void chk(int i, int j, int k) {
    int di = dr[k][0], dj = dr[k][1];
    for (int u = 1; u < (int)p.size(); u++) {
        int ii = i + u * di;
        int jj = j + u * dj;
        if (ii < 0 || ii >= n || jj < 0 || jj >= n || a[ii][jj] != p[u]) {
            return;
        }
    }
    for (int u = 0; u < (int)p.size(); u++) {
        int ii = i + u * di;
        int jj = j + u * dj;
        f[ii][jj] = a[ii][jj];
    }
}

int main() {
    memset(f, '*', sizeof(f));
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == p[0]) {
                for (int k = 0; k < 8; k++) {
                    chk(i, j, k);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << f[i][j];
        }
        cout << endl;
    }
    return 0;
}
