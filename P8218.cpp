#include <bits/stdc++.h>
using namespace std;
#define N 100'005
typedef long long ll;
ll a[N];
int n, m, l, r;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
    }
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &l, &r);
        printf("%lld\n", a[r] - a[l - 1]);
    }
    return 0;
}