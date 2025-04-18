#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005;
int n, s, v, d;
int a[N], dmax, ans;
int main() {
    cin >> n;
    while (n--) {
        cin >> s >> v >> d;
        int i = s / v;
        int j = i + d;
        dmax = max(dmax, j);
        a[i] += 1;
        a[j + 1] -= 1;
    }
    for (int i = 1; i <= dmax; ++i) {
        a[i] += a[i - 1];
        ans = max(ans, a[i]);
    }
    cout << ans;
    return 0;
}