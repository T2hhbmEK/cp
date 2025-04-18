#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int a[N][N];
struct T {
    int a, n;
} c[256];
int mp[256];

bool cmp(T x, T y) {
    if (x.n == y.n) return x.a < y.a;
    return x.n > y.n;
}

int fromHEX(char ch) {
    return isdigit(ch) ? ch - '0' : ch - 'A' + 10;
}

int main() {
    for (int i = 0; i < 256; i++) c[i].a = i;
    int n, m = 0;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        m = s.size() / 2;
        for (int j = 0; j < m; j++) {
            a[i][j] = fromHEX(s[j * 2]) * 16;
            a[i][j] += fromHEX(s[j * 2 + 1]);
            c[a[i][j]].n++;
        }
    }
    sort(c, c + 256, cmp);
    for (int i = 0; i < 16; i++) {
        printf("%02X", c[i].a);
    }
    cout << '\n';
    for (int i = 0; i < 256; i++) {
        int k = 0;
        for (int j = 0; j < 16; j++) {
            if (abs(i - c[j].a) < abs(i - c[k].a)) k = j;
        }
        mp[i] = k;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%X", mp[a[i][j]]);
        }
        cout << '\n';
    }
    return 0;
}
