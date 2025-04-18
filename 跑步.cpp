#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int LINF = 1e18 + 7;
const int N = 1e5 + 7;
ll a, b, c, t, tmin, tmp;
int main() {
    cin >> a >> b >> c >> t;
    if (t % a == 0 || t % b == 0 || t % c == 0) {
        cout << 0;
        return 0;
    }
    tmin = a - t % a;
    tmp = b - t % b;
    if (tmp < tmin) tmin = tmp;
    tmp = c - t % c;
    if (tmp < tmin) tmin = tmp;
    cout << tmin;
    return 0;
}