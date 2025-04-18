#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e;
char c1, c2, c3, c4;
int ck255(int x) {
    return x >= 0 && x <= 255;
}
int ck65535(int e) {
    return e >= 0 && e <= 65535;
}
int main() {
    cin >> a >> c1 >> b >> c2 >> c >> c3 >> d >> c4 >> e;
    if (ck255(a) && ck255(b) && ck255(c) && ck255(d) && ck65535(e) &&
        c1 == '.' && c2 == '.' && c3 == '.' && c4 == ':') {
        cout << a << " " << b << " " << c << " " << d << " " << e << " ";
    } else {
        cout << -1;
    }
    return 0;
}