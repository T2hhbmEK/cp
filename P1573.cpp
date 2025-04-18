#include <bits/stdc++.h>
using namespace std;
int n;
// a[i]
// 1 3 5 9 13 17 25 33 41 49 ...
// d[i]=a[i]-a[i-1]
// 1 2 2 4 4  4  8  8  8  8  ...
// c
// 1 2 2 3 3  3  4  4  4  4  ...
typedef long long ll;
int _mod(int x) {
    return x % 1000007;
}
int _modll(ll x) {
    return static_cast<int>(x % 1000007);
}
int _mult(int x, int y) {
    ll xx = static_cast<ll>(x);
    ll yy = static_cast<ll>(y);
    return _modll(xx * yy);
}
int main() {
    cin >> n;
    int a = 0;
    int d = 1;
    int c = 1;
    int i = 1;
    while (i + c - 1 <= n) {
        a = _mod(a + _mult(d, c));
        i += c;
        ++c;
        d = _mod(d * 2);
    }
    while (i <= n) {
        for (int j = 1; j <= c && i <= n; ++j) {
            a = _mod(a + d);
            // printf("%d\n", a);
            ++i;
        }
        ++c;
        d = _mod(d * 2);
    }
    cout << a << endl;
    return 0;
}