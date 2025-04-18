#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int f[MAXN][10];
bool vis[MAXN];
int cnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
bool chk(int a[10]) {
    int a1 = 1;
    while (a1 < 10 && a[a1] == 0) a1++;
    if (a1 >= 10) return false;
    return true;
}
int cmp(int a[10], int b[10]) {
    int na = 0, nb = 0;
    for (int i = 0; i < 10; i++) {
        na += a[i];
        nb += b[i];
    }
    if (na != nb) return na - nb;
    int a1 = 1, b1 = 1;
    while (a1 < 10 && a[a1] == 0) a1++;
    while (b1 < 10 && b[b1] == 0) b1++;
    if (a1 != b1) return a1 - b1;
    if (a[0] != b[0]) return b[0] - a[0];
    for (int i = a1; i < 10; i++) {
        if (a[i] != b[i]) return b[i] - a[i];
    }
    return 0;
}
void prt(int a[10]) {
    // for (int i = 0; i < 10; i++) cout << a[i] << (i == 9 ? '\n' : ' ');
    int a1 = 1;
    while (a1 < 10 && a[a1] == 0) a1++;
    if (a1 >= 10) {
        cout << -1 << '\n';
        return;
    }
    cout << a1;
    for (int i = 1; i <= a[0]; i++) cout << 0;
    for (int i = 1; i < a[a1]; i++) cout << a1;
    for (int j = a1 + 1; j < 10; j++) {
        for (int i = 1; i <= a[j]; i++) cout << j;
    }
    cout << '\n';
}
int main() {
    for (int i = 0; i <= (int)1e5; i++) {
        for (int j = 0; j < 10; j++) {
            int k = i - cnt[j];
            int b[10] = {};
            if (k >= 0 && chk(f[k])) {
                memcpy(b, f[k], sizeof b);
                b[j]++;
            } else if (k == 0) {
                b[j]++;
            }
            if (chk(b)) {
                if (!chk(f[i]) || cmp(f[i], b) > 0) {
                    // printf("%d %d %d:\n", i, j, k);
                    // prt(b);
                    memcpy(f[i], b, sizeof b);
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        prt(f[n]);
    }
    return 0;
}
