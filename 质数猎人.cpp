#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 10;
int minFactor[MAXN];
int ans[MAXN];
vector<int> primes;

void init() {
    int maxn = 1e7;
    for (int i = 2; i <= maxn; i++) minFactor[i] = i;
    for (int i = 2; i <= maxn; i++) {
        if (minFactor[i] == i) primes.push_back(i);
        for (int j = 0; j < primes.size() && primes[j] <= minFactor[i] &&
                        i * primes[j] <= maxn;
             j++) {
            minFactor[i * primes[j]] = primes[j];
        }
    }
    for (int i = 2; i <= maxn; i++) {
        ans[i] = ans[i - minFactor[i]] + 1;
    }
}

int min_factor(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return i;
    }
    return n;
}

void solve1() {
    int t;
    cin >> t;
    while (t--) {
        int n, cnt = 0;
        cin >> n;
        while (n) {
            n -= min_factor(n);
            cnt++;
        }
        cout << cnt << '\n';
    }
}

void solve() {
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
    return 0;
}
