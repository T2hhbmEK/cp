#include <bits/stdc++.h>
// #include <windows.h>
// #include <cstdlib>
using namespace std;

int n, m;
char a[15][15];

bool check(int i1, int j1, int i2, int j2) {
    int h = i2 - i1 + 1, w = j2 - j1 + 1;
    int sum = 0;
    for (int i = i1; i <= i2; i++) {
        for (int j = j1; j <= j2; j++) {
            if (a[i][j] == '1') {
                sum++;
            }
        }
    }
    return sum * 2 == h * w;
}

void draw(int i1, int j1, int i2, int j2) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i >= i1 && i <= i2 && j >= j1 && j <= j2) {
                cout << "x";
            } else {
                cout << "o";
            }
        }
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int i2 = i1; i2 < n; i2++) {
                for (int j2 = j1; j2 < m; j2++) {
                    int h = i2 - i1 + 1, w = j2 - j1 + 1;
                    if (check(i1, j1, i2, j2)) {
                        ans = max(ans, h * w);
                    }
                    // system("cls");
                    // draw(i1, j1, i2, j2);
                    // cout << endl;
                    // Sleep(500);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
