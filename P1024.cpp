// Problem: P1024 [NOIP2001 提高组] 一元三次方程求解
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1024
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
double a, b, c, d;

inline double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

double solve(double L, double R) {
    while (R - L > eps) {
        double mid = (L + R) / 2;
        if (f(L) * f(mid) <= 0) {
            R = mid;
        } else {
            L = mid;
        }
    }
    return L;
}

void test() {
    double x1, x2, x3;
    x1 = 0.5;
    x2 = -1.11;
    x3 = 1.5;
    //(x-x1)(x-x2)(x-x3)
    a = 1;
    b = -(x1 + x2 + x3);
    c = x1 * x2 + x1 * x3 + x2 * x3;
    d = -x1 * x2 * x3;
    cout << a << " " << b << " " << c << " " << d << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // test(), exit(0);
    cin >> a >> b >> c >> d;
    double step = 0.5;
    cout << fixed << setprecision(2);
    for (double i = -100; i <= 100; i += step) {
        if (f(i) == 0) {
            cout << i << ' ';
        } else if (f(i) * f(i + step) < 0) {
            cout << solve(i, i + step) << ' ';
        }
    }
    return 0;
}