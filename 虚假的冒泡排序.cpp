#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, ans;
struct T {
    int i, v;
} a[N];

bool cmp(T x, T y) {
    return x.v < y.v;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].v;
        a[i].i = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i += 2) {
        if (a[i].i % 2 != i % 2) ans++;
    }
    cout << ans;
    return 0;
}
