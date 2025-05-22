#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int NMAX = 1e2 + 5;
int n, a, cnt[NMAX], ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        cnt[a]++;
    }
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] > 0) {
            cout << i << " ";
            ans += cnt[i] - 1;
        }
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}
