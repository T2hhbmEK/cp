#include <bits/stdc++.h>
using namespace std;

int rational_sqrt(int& a) {
    int ans = 1;
    for (int i = 2, i2 = i * i; i2 <= a; ++i, i2 = i * i) {
        while (a % i2 == 0) {
            a /= i2;
            ans *= i;
        }
    }
    return ans;
}

pair<int, int> reduced_frac(int a, int b) {
    int f = 1;
    if (a < 0) f *= -1;
    if (b < 0) f *= -1;
    a = abs(a), b = abs(b);
    int c = __gcd(a, b);
    a /= c, b /= c;
    return {f * a, b};
}

void print_frac(pair<int, int> p) {
    cout << p.first;
    if (p.second != 1) cout << "/" << p.second;
}

void print_fracsqrt(pair<int, int> p, int delta) {
    if (p.first != 1) cout << p.first << "*";
    cout << "sqrt(" << delta << ")";
    if (p.second != 1) cout << "/" << p.second;
}

void solve(int a, int b, int c) {
    if (a < 0) a = -a, b = -b, c = -c;
    int delta = b * b - 4 * a * c;
    if (delta < 0) {
        cout << "NO" << endl;
        return;
    }
    int a2 = 2 * a;
    int q1 = -b;
    int q2 = rational_sqrt(delta);
    if (delta == 0 || delta == 1) {
        q1 += q2 * delta;
        q2 = 0;
        auto p1 = reduced_frac(q1, a2);
        print_frac(p1);
        cout << endl;
        return;
    }
    auto p1 = reduced_frac(q1, a2);
    auto p2 = reduced_frac(q2, a2);
    if (p1.first != 0) {
        print_frac(p1);
        cout << "+";
    }
    print_fracsqrt(p2, delta);
    cout << endl;
}

int main() {
    int t, m;
    cin >> t >> m;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        solve(a, b, c);
    }
    return 0;
}
