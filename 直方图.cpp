#include <iostream>
using namespace std;
int n, f, tj[100005];
int main() {
    cin >> n;
    //	tj[0] // 0 出现的次数
    //	tj[1] // 1 出现的次数
    //	tj[2] // 2 出现的次数
    //	tj[i] // i 出现的次数
    //	tj[x] // x 出现的次数
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x > f) {
            f = x;  // 求最大值
        }
        tj[x] += 1;  // 统计次数
    }
    for (int i = 0; i <= f; ++i) {
        cout << tj[i] << "\n";
    }
    return 0;
}
