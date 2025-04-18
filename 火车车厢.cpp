#include <iostream>
using namespace std;
int n, q, l, r;
int a[100005];
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while (q--) {
        cin >> l >> r;
        cout << a[r] - a[l - 1] << "\n";
    }
    return 0;
}