#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;
const double EPS = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9 + 7;
const int NMAX = 1e4;
int n, cnt[NMAX + 5], k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (cnt[x] == 0) k++;
        cnt[x]++;
    }
    k = k * 0.4;
    for (int i = NMAX; k && i >= 1; i--) {
        if (cnt[i]) {
            cout << i << " " << cnt[i] << endl;
            k--;
        }
    }
    return 0;
}
