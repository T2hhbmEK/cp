#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    ll x = 0;
    ll ni = 1;
    const ll N = 1e9;
    for (int i = 0; i <= m; i++) {
        x += ni;
        ni *= n;
        if (x > N) {
            cout << "inf";
            return 0;
        }
    }
    cout << x;
    return 0;
}
