#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    // 找出最高的进位，然后结果为a+b-最高位的权值

    // q表示权位，ans表示结果，t表示进位
    ll real_ans = a + b;
    ll q = 1, ans = a + b, t = 0;
    // 从低位开始模拟计算
    while (a != 0 || b != 0) {
        // 当前个位
        q *= 10;
        int ga = a % 10, gb = b % 10;
        t = (ga + gb + t) / 10;
        if (t > 0) {  // 发生进位
            ans = min(ans, real_ans - q);
        }
        a /= 10;
        b /= 10;
    }

    cout << ans << endl;

    return 0;
}
