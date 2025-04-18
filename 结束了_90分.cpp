/* 形如：
 *      .      j                   i
 *     ...     j-1, j+1            i+1
 *    .....    j-2, j+2            i+2
 *   .......
 *  .........  j-(k-2), j+(k-2)    i+(k-2)
 *      .      j                   i+(k-1)
 * 注意：不要使用 y1 这种变量名，会和 cmath 中的 y1 函数冲突，会爆 0 ！！！
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 500 + 5;
int n, m, a[maxn][maxn], ans;

bool check(int x, int y, int k) {
    for (int i = 0; i <= k - 2; ++i) {
        int xx = x + i;
        int l = y - i, r = y + i;
        for (int yy = l; yy <= r; ++yy) {
            if (a[xx][yy] != 1) {
                return false;
            }
        }
    }
    if (a[x + k - 1][y] != 1) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    // 枚举所有的情况并判断
    for (int k = 2; k <= n && 2 * k - 3 <= m; ++k) {
        for (int i = 1; i + k - 1 <= n; ++i) {
            for (int j = k - 1; j + k - 2 <= m; ++j) {
                if (check(i, j, k)) ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
