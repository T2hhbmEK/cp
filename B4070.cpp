#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, ans;

int f(int x) {
    int s = 0;
    for (int i = 1; i <= x; i++) {
        x -= i;
        s++;
    }
    return s;
}

int main() {
    cin >> n;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        int sum = 0;
        while (n % p == 0) {
            n /= p;
            sum++;
        }
        ans += f(sum);
    }
    if (n > 1) {
        ans += 1;
    }
    cout << ans;
    return 0;
}