#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e8;
int maxk = 0;
int len[100];

char f(int k, int n) {
    assert(n <= len[k]);
    if (k == 0) return "_tee"[n];
    if (n <= len[k - 1]) return f(k - 1, n);
    n -= len[k - 1];
    if (n == 1) return 't';
    if (n <= k + 3) return 'e';
    n -= k + 3;
    return f(k - 1, n);
}

int main() {
    int k = 0, n = 3;
    len[0] = 3;
    while (n <= MAXN + 1) {
        k++;
        n = n * 2 + k + 3;
        len[k] = n;
        maxk = k;
    }
    int t;
    cin >> t;
    // for (int i = 1; i <= 100; i++) cout << f(maxk, i);
    while (t--) {
        int n;
        cin >> n;
        cout << f(maxk, n) << '\n';
    }
    return 0;
}
