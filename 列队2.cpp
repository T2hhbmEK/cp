#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;
int lcm(int a, int b) { return a / __gcd(a, b) * b; }
signed main() {
    freopen("line.in", "r", stdin);
    freopen("line.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    int x, a, b;
    cin >> x;
    b = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int _a = i;
            int _b = x / i;
            if (lcm(_a, _b) == x) b = x / i;
        }
    }
    cout << x / b << ' ' << b << endl;
    return 0;
}
