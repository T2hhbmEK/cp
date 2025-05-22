#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int a = 1; a < n; a++) {
        for (int b = a; a * a + b * b <= n * n; b++) {
            int c = sqrt(a * a + b * b);
            if (a * a + b * b == c * c) ans++;
        }
    }
    cout << ans;
    return 0;
}
