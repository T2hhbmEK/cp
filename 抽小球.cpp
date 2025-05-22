#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                cout << i << " " << j << "\n";
            }
        }
    }
    return 0;
}
