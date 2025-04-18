/*
12345678
x  x  x
23568
12345
x  x
358
x
58
x
8
 */
#include <bits/stdc++.h>
using namespace std;

int cnt, ans;

void f(int n) {
    // 增加天数
    cnt++;
    // 如果还没有找到答案，并且 n 除以 3 余 1，记录当前天数为答案
    if (ans == 0 && n % 3 == 1) ans = cnt;
    // 如果 n 等于 1，结束计算
    if (n == 1) return;
    // 计算本轮需要删除的数字数量
    int x = (n + 2) / 3;  // n 除以 3 向上取整
    // 计算删除后的剩余数字
    f(n - x);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    f(n);
    cout << cnt << " " << ans << endl;
    return 0;
}
