#include <bits/stdc++.h>
using namespace std;
#define N 5005
int n, m;
typedef struct {
    int k;
    int s;
} KS;
KS ks[N];
bool cmp(KS &x, KS &y) {
    if (x.s > y.s) {
        return true;
    }
    if (x.s < y.s) {
        return false;
    }
    return x.k < y.k;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &ks[i].k, &ks[i].s);
    }
    sort(ks, ks + n, cmp);
    m = m * 3 / 2;
    int s = ks[m-1].s;
    int cnt = 0;
    for (int i = 0; i < n && ks[i].s >= s; ++i) {
        cnt++;
    }
    printf("%d %d\n", s, cnt);
    for (int i = 0; i < cnt; ++i) {
        printf("%d %d\n", ks[i].k, ks[i].s);
    }
    return 0;
}