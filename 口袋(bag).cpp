/* 思路：
 * - 选择 1 的个数尽量少，-1 的个数尽量多，这样可以让平均数最大
 * - 数学证明（略）
 * - 最差情况，0 全部选择 1，检查是否可行，
 *   如果这样都不可行，直接输出 -1，提前结束
 * - 二分答案，假设 0 选择 mid 个 1，检查是否可行，
 *   如果可行，将右边界移到 mid，否则将左边界移到 mid + 1
 * - 复杂度分析：每次检查的复杂度是 O(n)，二分的复杂度是 O(logn)
 *   所以总的复杂度是 O(tnlogn) ~= O(5 * 10^6 * 20) = O(10^8)
 * 优化：
 * - 快读，减少输入输出的时间，
 *   大量输入，快读比 cin 快很多，这里快一倍以上
 * - 位运算快速计算除以 2，四则运算中，+ - * 的速度差不多，
 *   但是 / 和 % 的速度慢很多，所以尽量避免使用 / 和 %，可以用位运算代替
 */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxn = 1e6 + 5;
int t, n, a[maxn], p, q, z, last;

int read() {           // 快读，读入一个整数
    int x = 0, f = 1;  // x: 读入的整数, f: 正负号
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

int gcd(int a, int b) {  // 求最大公约数
    while (b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

bool check(int x) {                    // 检查选择 x 个 1 是否可行
    int q = 1;                         // q: 数的个数
    for (int i = 1; i <= last; ++i) {  // 末尾的连续 1 不用检查
        q += a[i];                     // 选择 1 或 -1
        if (a[i] == 0) {
            if (x) {  // 先选 1，选够 x 个 1 之后再选 -1
                q += 1;
                x -= 1;
            } else {
                q -= 1;
            }
        }
        if (q <= 0) return 0;  // 不可行
    }
    return 1;  // 可行
}

void solve() {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    p = 1, q = 1, z = 0, last = 0;  // p: 所有数的和, q: 数的个数, z: 0 的个数
                                    // last: 最后一个 0 或 -1 的位置
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 1) {
            p += 1;
            q += 1;
        } else if (a[i] == -1) {
            q -= 1;
            last = i;
        } else if (a[i] == 0) {
            z += 1;
            last = i;
        }
    }
    // 0 全部选择 1，检查是否可行，如果不可行，输出 -1，提前结束
    if (!check(z)) {
        cout << -1 << endl;
        return;
    }
    // 二分答案，假设 0 选择 mid 个 1，检查是否可行
    int l = 0, r = z;
    while (l < r) {
        int mid = (l + r) >> 1;  // 位运算快速计算除以 2
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    // 更新 p 和 q
    p += l;
    q += l;
    q -= z - l;  // 选择 -1 的次数是 z - l
    // 约分
    int s = gcd(p, q);
    p /= s;
    q /= s;
    cout << p << ' ' << q << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    t = read();
    while (t--) {
        solve();
    }
    return 0;
}
