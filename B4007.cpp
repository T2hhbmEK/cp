#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int a = i;
        while (a) {
            if (a % 10 == k) ans++;
            a /= 10;
        }
    }
    cout << ans;
    return 0;
}
