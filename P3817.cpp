#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n, x, a[N];
typedef long long ll;
ll ans;
int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        int e = a[i] + a[i - 1] - x;  // eat
        if (e > 0) {
            ans += e;
            a[i] -= e;
        }
    }
    cout << ans << endl;
    return 0;
}