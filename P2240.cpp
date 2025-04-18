#include <bits/stdc++.h>
using namespace std;
#define N 105
typedef struct {
    int m;
    int v;
} A;
A a[N];
int n, t;
float ans;
bool cmp(A x, A y) {
    return x.v * y.m > y.v * x.m;
}
int main() {
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].m, &a[i].v);
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n && t > 0; ++i) {
        if (a[i].m < t) {
            t -= a[i].m;
            ans += a[i].v;
        } else {
            ans += static_cast<float>(t) * a[i].v / a[i].m;
            t = 0;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
