#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;
    for (int i = 2; (ll)i * i <= n; i++) {
        int k = 0;
        while (n % i == 0) {
            k++;
            n /= i;
        }
        if (k == 0) continue;
        cout << i;
        if (k > 1) {
            cout << "^" << k;
        }
        cout << " * ";
    }
    cout << n;
    return 0;
}
