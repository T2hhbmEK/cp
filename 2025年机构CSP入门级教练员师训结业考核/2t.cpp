#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m = 3;
    cin >> n;
    int s = n;
    while (n >= m) {
        s += n / m;
        n = n / m + n % m;
    }
    cout << s << endl;
    return 0;
}
