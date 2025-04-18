#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4 + 10;
int n, w;
int p[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> w >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    int ans = 0;
    for (int i = 1, j = n; i <= j;) {
        if (i < j && p[i] + p[j] > w) {
            if (p[j] <= w) ans++;
            j--;
        } else {
            ans++;
            i++, j--;
        }
    }
    cout << ans << endl;
    return 0;
}
