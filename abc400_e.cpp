#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int N = 1e6;

int q, a;
vector<int> primes;
int ff[N + 5];
int f[N + 5];
int ans[N + 5];

void init() {
    for (int i = 0; i <= N; i++) ff[i] = i;
    ff[0] = ff[1] = -1;
    for (int i = 2; i <= N; i++) {
        if (ff[i] == i) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > N) break;
            ff[i * p] = p;
            if (p % i == 0) break;
        }
    }
    for (int i = 2; i <= N; i++) {
        unordered_set<int> fs;
        int a = i;
        while (a > 1) {
            fs.insert(ff[a]);
            a /= ff[a];
        }
        f[i] = fs.size() == 2;
    }
    for (int i = 6; i <= N; i++) {
        if (f[i]) {
            ans[i] = i;
        } else {
            ans[i] = ans[i - 1];
        }
    }
}

signed main() {
    init();
    cin >> q;
    while (q--) {
        cin >> a;
        a = sqrt(a);
        cout << ans[a] * ans[a] << endl;
    }
    return 0;
}
