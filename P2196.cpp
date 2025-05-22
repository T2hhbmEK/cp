#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
using vi = vector<int>;
using vii = vector<vi>;

void fp(int k, const vi &pr) {
    if (k == 0) return;
    fp(pr[k], pr);
    cout << k << " ";
}

int main() {
    int n, x;
    cin >> n;
    vi a(n + 1);
    rep(i, 1, n) cin >> a[i];
    vii pa(n + 1);
    rep(i, 1, n) rep(j, i + 1, n) {
        if (cin >> x, x) {
            pa[j].push_back(i);
        }
    }
    vi pr(n + 1);
    rep(i, 1, n) {
        int m = 0;
        for (int j : pa[i]) {
            if (a[j] > a[m]) m = j;
        }
        pr[i] = m, a[i] += a[m];
    }
    int m = 0;
    rep(i, 1, n) if (a[i] > a[m]) m = i;
    fp(m, pr);
    cout << endl << a[m];
    return 0;
}
