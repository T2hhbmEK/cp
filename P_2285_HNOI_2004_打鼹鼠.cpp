#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5, maxm = 1e4 + 5;
const int dr[4][2] = {
    {-1, 0},
    {+1, 0},
    {0, -1},
    {0, +1},
};

int n, m;
int f[maxm];  // f[i]: max kills after kill mole i
struct T {
    int t, x, y;
} a[maxm];

int fd(int i, int j) {
    return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].t >> a[i].x >> a[i].y;
        f[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j].t + fd(j, i) <= a[i].t) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }
    cout << *max_element(f + 1, f + 1 + m);
    return 0;
}
