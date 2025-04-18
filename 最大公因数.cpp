#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL gcd(LL a, LL b) {
    if (b==0) return a;
    return gcd(b, a % b);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        LL a, b;
        cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }
    return 0;
}
