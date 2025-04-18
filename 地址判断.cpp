#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e;
char c1, c2, c3, c4, c5;
void rd(int &x, char &c) {
    c = getchar();
    int f = 1;
    while (c != EOF && !isdigit(c)) {
        if (c == '-') {
            f = -1;
        }
        c = getchar();
    }
    x = 0;
    while (isdigit(c)) {
        x *= 10;
        x += c - '0';
        c = getchar();
    }
    x *= f;
}
int ck255(int x) {
    return x >= 0 && x <= 255;
}
int ck65535(int e) {
    return e >= 0 && e <= 65535;
}
int main() {
    rd(a, c1);
    rd(b, c2);
    rd(c, c3);
    rd(d, c4);
    rd(e, c5);
    if (ck255(a) && ck255(b) && ck255(c) && ck255(d) && ck65535(e) &&
        c1 == '.' && c2 == '.' && c3 == '.' && c4 == ':') {
        cout << a << " "
             << b << " "
             << c << " "
             << d << " "
             << e << " ";
    } else {
        cout << -1;
    }
    return 0;
}