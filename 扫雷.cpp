#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n, m;
char a[N][N];

char f(int x, int y) {
    char ch = '0';
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (a[i][j] == '*') {
                ch++;
            }
        }
    }
    return ch;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (a[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '?') {
                a[i][j] = f(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (a[i] + 1) << '\n';
    }
    return 0;
}
