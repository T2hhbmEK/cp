#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, b, f[N], ans;
vector<int> primes;

int main() {
    cin >> n >> b;
    for (int i = 2; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 2; i <= n; i++) {
        if (f[i] == i) {
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() && primes[j] * i <= n; j++) {
            f[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
    for (int i = 1; i <= n; i++) {
        int a = i, x = 1;
        while (a > 1) {
            x = f[a];
            a /= x;
        }
        if (x <= b) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
