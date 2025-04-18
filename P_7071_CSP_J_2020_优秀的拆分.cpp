#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    if (n & 1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = (1 << 30); i > 1; i >>= 1) {
        int x = n & i;
        if (x) cout << x << ' ';
    }
    return 0;
}
