#include <bits/stdc++.h>
using namespace std;
#define N 410
int n;
bool is366(int y) {
    if (y % 400 == 0 || y % 100 != 0 && y % 4 == 0) return true;
    return false;
}
//                     1   2   3   4   5   6   7   8   9  10  11  12
int dCnt365[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dCnt366[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int weekday = 0;
int ans[8];
int main() {
    cin >> n;
    for (int y = 1900; y < 1900 + n; ++y) {
        for (int m = 1; m <= 12; ++m) {
            int dCnt = is366(y) ? dCnt366[m] : dCnt365[m];
            for (int d = 1; d <= dCnt; ++d) {
                if (++weekday > 7) {
                    weekday = 1;
                }
                if (d == 13) {
                    ++ans[weekday];
                    // cout << y << " " << m << " " << d << " " << weekday << "\n";
                }
            }
        }
    }
    for (const auto &i : {6, 7, 1, 2, 3, 4, 5}) {
        cout << ans[i] << " ";
    }
    return 0;
}