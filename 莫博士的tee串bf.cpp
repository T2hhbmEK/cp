#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e8;

char a[MAXN * 2] = "tee";
int n = 3;

void init() {
    for (int k = 1; n < MAXN; k++) {
        if (n >= MAXN) break;
        a[n] = 't';
        for (int i = 0, j = n + 1; j < MAXN && i < k + 2; i++, j++) {
            a[j] = 'e';
        }
        strncpy(a + n + k + 3, a, n);
        n = n * 2 + k + 3;
    }
}

int main() {
    init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << a[n - 1] << '\n';
    }
    return 0;
}
