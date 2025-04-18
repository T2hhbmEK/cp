#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int a[3], x[3];
bool t[N][N][N], ans[N];
void p() {
    for (int i = 0; i < 3; ++i) cout << x[i] << " ";
    cout << "\n";
}
void dfs() {
    if (t[x[0]][x[1]][x[2]]) {
        return;
    }
    t[x[0]][x[1]][x[2]] = true;
    if (x[0] == 0) {
        ans[x[2]] = true;
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            if (x[i] != 0 && x[j] < a[j]) {
                int xx[3];
                memcpy(xx, x, sizeof(x));
                if (x[i] + x[j] <= a[j]) {
                    x[j] += x[i];
                    x[i] = 0;
                } else {
                    x[i] = x[i] + x[j] - a[j];
                    x[j] = a[j];
                }
                dfs();
                memcpy(x, xx, sizeof(x));
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a[0] >> a[1] >> a[2];
    x[2] = a[2];
    dfs();
    for (int i = 0; i <= a[2]; ++i) {
        if (ans[i]) cout << i << " ";
    }
    return 0;
}