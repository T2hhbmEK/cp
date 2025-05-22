#include <bits/stdc++.h>
using namespace std;

int n;

bool is_prime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 3, j = 5; j <= n; i += 2, j += 2) {
        if (is_prime(i) && is_prime(j)) {
            cout << i << " " << j << '\n';
        }
    }
    return 0;
}
