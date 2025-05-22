/* 思路：
 * a[i][j] = (a[i-1][j] + 1) / 2 + k
 * a[i][j] - 2 * k - 1 = (a[i-1][j] - 2 * k - 1) / 2
 * 记 b[i][j] = a[i][j] - 2 * k - 1
 * b[i][j] = b[i-1][j] / 2
 * 除 32 次之后就一直为 0 了，可以省略
 * 同理，经过 32 次变换之后 a[i][j] 一定不会再变化
 * 保险一点，可以算 32+5=37 次
 * m >= 37 时，直接输出 s[36] 即可
 * m < 37 时，输出 s[m] 即可
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 * 
 * 其实，可以暴力模拟，然后发现当 m 足够大时，s[i] 会趋于一个常数
 */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
const int maxn = 1e5 + 5;
const int maxm = 32 + 5;  // int 32 位，除 32 次之后一定就相等了
int n, k, q, m, a[maxm][maxn];
ll s[maxm];
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[0][i];
    }
    for (int i = 1; i < maxm; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = ((a[i - 1][j] + 1) >> 1) + k;
            s[i] += a[i][j];
        }
    }
    while (q--) {
        cin >> m;
        if (m >= maxm) {
            cout << s[maxm - 1] << endl;
        } else {
            cout << s[m] << endl;
        }
    }
    return 0;
}
