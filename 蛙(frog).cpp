/* 思路：
 * 1. 二分答案，假设每个孩子最多分配 x 只青蛙，检查是否可以将青蛙分配给孩子
 * 2. 如果可以，将右边界移到中间值，否则将左边界移到中间值的右边
 * 3. 输出最小的 x 值
 */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxm = 3e5 + 5;  // 最大的 m 值
const int maxa = 1e9;      // 最大的 a 值
int n, m, a[maxm];  // n 表示孩子数，m 表示青蛙种类数，a 数组存储每种青蛙的数量

// 检查是否可以将青蛙分配给孩子，每个孩子最多分配 x 只青蛙
bool check(int x) {
    int sum = 0;  // 至少需要的孩子数
    for (int i = 1; i <= m; ++i) {
        sum += (a[i] + x - 1) / x;  // 向上取整计算需要的孩子数
        if (sum > n) return 0;  // 如果需要的孩子数超过 n，返回 false
    }
    return 1;  // 如果可以分配，返回 true
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);  // 加速输入输出流
    cin >> n >> m;                        // 读入孩子数和青蛙种类数
    for (int i = 1; i <= m; ++i) cin >> a[i];  // 读入每种青蛙的数量
    // 二分答案 O(mlog(maxa))
    int l = 1, r = maxa;  // 初始化二分查找的左右边界
    while (l < r) {
        int mid = (l + r) / 2;  // 计算中间值
        if (check(mid)) {       // 检查是否可以分配
            r = mid;            // 如果可以，将右边界移到中间值
        } else {
            l = mid + 1;  // 如果不可以，将左边界移到中间值的右边
        }
    }
    cout << l << endl;  // 输出最小的 x 值
    return 0;
}
