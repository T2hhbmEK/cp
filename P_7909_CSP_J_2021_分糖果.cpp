#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, l, r;
    cin >> n >> l >> r;
    int k = l / n * n + n - 1;
    if (k <= r) {
        cout << n - 1 << endl;
    } else {
        cout << r % n << endl;
    }
    return 0;
}
