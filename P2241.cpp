#include <bits/stdc++.h>
#define maxn 5010
#define int long long
using namespace std;

int n, m;

signed main() {
    cin >> n >> m;
    int cnt_sq = 0;
    int cnt_rec = 0;
    int mi = min(n, m);
    for (int a = 1; a <= mi; a++) {
        cnt_sq += (n - a + 1) * (m - a + 1);
    }
    cnt_rec = ((n + 1) * n / 2) * ((m + 1) * m / 2);
    cnt_rec -= cnt_sq;
    cout << cnt_sq << " " << cnt_rec << endl;
    return 0;
}
