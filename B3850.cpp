#include <bits/stdc++.h>
using namespace std;

#define int long long

int sum_digits(int a) {
    int sum = 0;
    while (a) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int ff(int a, int k = 1) {
    if (a == 0) return a;
    int x = a % 10;
    if (k % 2 != 0) {
        x *= 7;
        while (x > 9) {
            x = sum_digits(x);
        }
    }
    return ff(a / 10, k + 1) * 10 + x;
}

int t[10] = {0, 7, 5, 3, 1, 8, 6, 4, 2, 9}; // 对应关系
int f(int a) {
    int s[15] = {};
    int n = 0;
    while (a) {
        s[++n] = a % 10;  // 个位存在 s[1]
        a /= 10;
    }
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) continue;
        s[i] = t[s[i]];
    }
    int b = 0;
    for (int i = n; i >= 1; i--) {
        b *= 10;
        b += s[i];
    }
    return b;
}

signed main() {
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        int b = f(a);
        // cout << b << endl;
        cout << "FT"[sum_digits(b) % 8 == 0] << '\n';
    }
    return 0;
}
