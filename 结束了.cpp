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
const int maxn = 500 + 5;
int n, m, a[maxn][maxn], ans;
int pre[maxn][maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            pre[i][j] = pre[i][j - 1] + a[i][j];  // 前缀和
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            // 圣诞树树冠位置 i, j
            // 枚举树的高度
            // 注意到存在高为 k 的树时，必定存在高度 1 - k-1 的树
            // 每次只需要判断新增加的一层是否符合条件即可
            for (int k = 2; i + k - 1 <= n; ++k) {
                int l = j - k + 2, r = j + k - 2;
                if (l < 1 || r > m) break;
                int x = i + k - 2;
                // int flag = 1;
                // for (int y = l; y <= r; ++y) {
                //     if (a[x][y] != 1) {
                //         flag = 0;
                //         break;
                //     }
                // }
                // if (!flag) break;
                // 用前缀和优化区间判断
                int sum = pre[x][r] - pre[x][l - 1];
                if (sum != r - l + 1) break;  // 和应该等于区间长度
                if (a[x + 1][j] != 1) break;  // 树干
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
