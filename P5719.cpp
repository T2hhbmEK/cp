#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a = 0, cnta = 0, b = 0, cntb = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            a += i, cnta++;
        } else {
            b += i, cntb++;
        }
    }
    cout << fixed << setprecision(1);
    cout << (double)a / cnta << " " << (double)b / cntb << endl;
    return 0;
}
