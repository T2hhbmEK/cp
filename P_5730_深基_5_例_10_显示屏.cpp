#include <iostream>
using namespace std;

constexpr char t[8][64] = {
    "XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX.",
    "X.X...X...X...X.X.X.X...X.....X.X.X.X.X.",
    "X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX.",
    "X.X...X.X.....X...X...X.X.X...X.X.X...X.",
    "XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX.",
};
char a[8][512], s[128];

int main() {
    int n;
    cin >> n >> s;
    for (int k = 0, x; k < n; k++) {
        x = s[k] - '0';
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < (k == n - 1 ? 3 : 4); j++) {
                a[i][j + k * 4] = t[i][j + x * 4];
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        cout << a[i] << endl;
    }
    return 0;
}
