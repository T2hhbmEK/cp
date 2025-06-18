#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, mi = 1000, ma = 0;
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        mi = min(mi, a);
        ma = max(ma, a);
    }
    cout << ma - mi << endl;
    return 0;
}
