#include <iostream>
using namespace std;
int n, m, l, r;
int a[100005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    cin >> m;
    while (m--) {
        cin >> l >> r;
        cout << a[r] - a[l - 1] << "\n";
    }
    return 0;
}