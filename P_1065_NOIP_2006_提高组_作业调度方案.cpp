#include <bits/stdc++.h>
#define maxn 30
#define maxnn 410
#define maxt 8010
using namespace std;

int m, n, ans;
int s[maxnn];       // order
int a[maxn][maxn];  // no. of machine
int b[maxn][maxn];  // time consumption
int cnt[maxn];      // no. of processed parts
int lst[maxn];      // last t
int t[maxn][maxt];  // time slots

void prt() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= ans; j++) {
            cerr << t[i][j] << " ";
        }
        cerr << "\n";
    }
    cerr << "\n";
}

int find(int a[], int pos, int len) {
    for (int i = pos; i < pos + len; i++) {
        if (a[i] != 0) return find(a, i + 1, len);
    }
    return pos;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m * n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }
    for (int k = 1; k <= m * n; k++) {
        int prod_id = s[k];
        int part_id = ++cnt[prod_id];
        int machine_id = a[prod_id][part_id];
        int time_cost = b[prod_id][part_id];
        int j = find(t[machine_id], lst[prod_id] + 1, time_cost);
        for (int jj = j; jj < j + time_cost; jj++) {
            t[machine_id][jj] = prod_id;
        }
        lst[prod_id] = j + time_cost - 1;
        ans = max(ans, lst[prod_id]);
        // prt();
    }
    cout << ans;
    return 0;
}
