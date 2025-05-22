#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, m;
    cin >> t >> m;
    vector<int> a(m), v(m);
    for (int i = 0; i < m; i++) cin >> a[i] >> v[i];
    vector<int> f(t + 1);
    for (int i = 0; i < m; i++) {
        for (int j = t; j >= a[i]; j--) {
            f[j] = max(f[j - a[i]] + v[i], f[j]);
        }
    }
    cout << f[t];
    return 0;
}
