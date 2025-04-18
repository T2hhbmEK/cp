#include <bits/stdc++.h>
using namespace std;
#define N 50005
int l, n, m, d[N];
void p(int *d, int n) {
    for (int i = 0; i <= n; i++) {
        printf("%-3d", d[i]);
    }
    cout << endl;
}
bool tst(int x) {
    int c = 0;
    int i = 0;
    int j = 1;
    int nn = n;
    while (d[n + 1] - d[nn] < x) {
        if (++c > m) {
            return false;
        }
        nn--;  // rm nn
    }
    // p(d, nn);
    // printf("%-3d", 0);
    while (j <= nn) {
        if (d[j] - d[i] < x) {
            if (++c > m) {
                // cout << endl;
                return false;
            }
            // printf("x  ");
            j++;  // rm j
        } else {
            // printf("%-3d", d[j]);
            i = j++;
        }
    }
    // cout << endl;
    return true;
}
int f(int i, int j) {  // [i,j)
    if (i + 1 == j) {
        return i;
    }
    int k = (i + j) / 2;
    if (tst(k)) {
        return f(k, j);  // [k,j)
    } else {
        return f(i, k);  // [i,k)
    }
}
int main() {
    cin >> l >> n >> m;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &d[i]);
    }
    d[n + 1] = l;
    cout << f(1, l / (n - m + 1) + 1) << endl;
    return 0;
}
