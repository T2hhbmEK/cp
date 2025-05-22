#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int N = 1e5;
const int INF = 0x3f3f3f3f;
bitset<N + 1> not_prime;
vector<int> primes;
int cnt[2];

void init() {
    not_prime[0] = not_prime[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!not_prime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() && primes[j] * i <= N; j++) {
            not_prime[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    int h;
    cin >> h;
    if (!not_prime[h]) {
        cout << 1 << endl;
        return;
    }
    for (int i = 1, x = 1; x <= h; i++, x = (x << 1) + 1) {
        if (!not_prime[h - x]) {
            cout << i + 1 << endl;
            return;
        } else if (h == x) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
