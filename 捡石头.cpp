#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
int n, m, cnt;
int main() {
    cin >> n >> m;
    if (n > m) swap(n, m);
    for (int i = n + 1; i < m; i++) {
        int j = 30 - n - m - i;
        if (j > n && j < m && i <= j) {
            cout << i << " " << j << "\n";
            cnt += 1;
        }
    }
    if (cnt == 0) {
        cout << 0 << " " << 0 << "\n";
    }
    return 0;
}