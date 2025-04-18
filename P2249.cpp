#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n, m, a[N], q;
int f(int q, int i, int j) {  // (i,j] => (i,k] (k,j]
    if (i >= j) {
        return -1;
    }
    if (i + 1 == j) {
        if (a[j] == q) {
            return j;
        } else {
            return -1;
        }
    }
    int k = (i + j) / 2;
    if (q <= a[k]) {
        return f(q, i, k);
    } else {
        return f(q, k, j);
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &q);
        printf("%d ", f(q, 0, n));
    }
    return 0;
}