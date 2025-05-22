#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXV = 1e4 + 5;
const int INF = 0x3f3f3f3f;

int n, a[MAXN], sum;
bitset<MAXV * MAXN> f;
int ans = INF;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    f[0] = 1;
    for (int i = 0; i <= sum; i++) {
        if (f[i]) {
            
        }
    }
    cout << ans;
    return 0;
}
