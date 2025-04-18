#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n = 6;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = max(i, j) + 1; k <= n; ++k) {
                cout << i << " " << j << " " << k << "\n";
            }
        }
    }
    return 0;
}
