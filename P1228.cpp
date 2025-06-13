#include <bits/stdc++.h>
#define maxn 1026
using namespace std;

int xy2c[2][2] = {
    {1, 2},
    {3, 4},
};
int c2xy[5][2] = {
    {0, 0}, {2, 2}, {2, 1}, {1, 2}, {1, 1},
};
int cinv[5] = {0, 4, 3, 2, 1};

void g(int n, int c, int dx, int dy) {
    // cout << n << " " << c << " " << dx << " " << dy << endl;
    if (n == 2) {
        cout << dx + c2xy[c][0] << " ";
        cout << dy + c2xy[c][1] << " ";
        cout << c << endl;
        return;
    }
    int h = n >> 1, q = n >> 2;
    g(h, c, dx + q, dy + q);
    for (int i = 1; i <= 4; i++) {
        if (i == cinv[c]) continue;
        if (i == 1) g(h, i, dx + h, dy + h);
        if (i == 2) g(h, i, dx + h, dy);
        if (i == 3) g(h, i, dx, dy + h);
        if (i == 4) g(h, i, dx, dy);
    }
}
void f(int x, int y, int n, int dx, int dy) {
    if (n == 1) return;
    int hf = n >> 1, c = xy2c[!(x <= hf)][!(y <= hf)];
    g(n, c, dx, dy);
    if (x > hf) x -= hf, dx += hf;
    if (y > hf) y -= hf, dy += hf;
    f(x, y, hf, dx, dy);
}

int main() {
    int k, x, y, n;
    cin >> k >> x >> y;
    n = 1 << k;
    f(x, y, n, 0, 0);
    return 0;
}
