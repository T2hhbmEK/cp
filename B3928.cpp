#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int u[N], v[N];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(u, u + n);
    sort(v, v + n);
    
    int L = 0, R = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (u[R] > v[i]) {
            R--, ans++;
        } else {
            L++;
        }
    }
    
    // for (int i = 0, j = 0; i < n && j < n; j++) {
        // while (i < n && u[i] < v[j]) i++;
        // if (i < n && u[i] > v[j]) ans++, i++;
    // }
    cout << ans;
    return 0;
}
