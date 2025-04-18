#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    int n, a;
    cin >> n;
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans = lcm(ans, a);
    }
    cout << ans;
    return 0;
}
