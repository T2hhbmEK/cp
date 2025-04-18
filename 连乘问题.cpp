#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int MOD = 10000;
int n, a[N], l[N], r[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    l[0] = 1;
    for (int i = 1; i <= n; ++i) {
        l[i] = l[i - 1] * a[i];
        l[i] %= MOD;
    }
    r[n + 1] = 1;
    for (int i = n; i >= 1; --i) {
        r[i] = r[i + 1] * a[i];
        r[i] %= MOD;
    }
    for (int i = 1; i <= n; ++i) {
        cout << (l[i - 1] * r[i + 1]) % MOD << "\n";
    }
    return 0;
}