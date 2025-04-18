#include <iostream>
using namespace std;

const int maxn = 1e6 + 10;
int n, a[maxn], pos[maxn];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) pos[a[i]] = i;  // 编号为 a[i] 的棋子的位置是 i
    for (int i = 1; i < n; ++i) {
        swap(pos[i], pos[0]);  // 交换编号为 i 和 0 的棋子的位置
    }
    for (int i = 0; i < n; ++i) a[pos[i]] = i;  // 更新编号
    for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    return 0;
}
