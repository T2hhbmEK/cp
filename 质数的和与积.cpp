#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vii = vector<vi>;
using viii = vector<vii>;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
void solve() {
    int s;
    cin >> s;
    int ans = 0;
    for (int i = 2, j = s - i; i + i <= s; i++, j--) {
        if (is_prime(i) && is_prime(j)) {
            ans = max(ans, i * j);
        }
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}
