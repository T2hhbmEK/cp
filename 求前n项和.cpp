#include <iomanip>
#include <iostream>
using namespace std;
const int MAXN = 30 + 5;
int n, a[MAXN] = {0, 1, 1};  // 斐波那契数列
double sum;                  // 默认为0
int main() {
    cin >> n;
    for (int i = 3; i <= n + 1; ++i) {
        a[i] = a[i - 1] + a[i - 2];  // 递推求斐波那契数列
    }
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 * a[i] / a[i + 1];  // 注意类型转换
    }
    cout << fixed << setprecision(3) << sum;
    return 0;
}
