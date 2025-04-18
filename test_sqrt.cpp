#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int n = 1e8, sum;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= n; i++) {
        // sum += sqrt(i);
        // sum += i * i;
        // sum += n / i;
        sum += i + i;
        // sum += cbrt(i);
    }
    return 0;
}
