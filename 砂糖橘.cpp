#include <iostream>
using namespace std;

const int maxn = 200 + 10;
const int maxm = 1500 + 10;
int n, w, m, mi, a[maxn], b[maxm];

int main() {
    cin >> n >> w >> m;
    for (int i = 1; i <= n; ++i) {
        a[i] = w;  // a表示编号为i的车辆所剩余的重量
    }
    for (int j = 1; j <= m; ++j) {
        cin >> mi;  // mi表示第j个区县的需求量
        b[j] = -1;  // b表示第j个区县的车辆编号，默认为-1
        for (int i = 1; i <= n; ++i) {  // 从编号为1的车辆开始遍历
            if (a[i] >= mi) {  // 如果编号为i的车辆剩余重量大于等于mi
                a[i] -= mi;  // 则编号为i的车辆剩余重量减去mi
                b[j] = i;    // 第j个区县的车辆编号为i
                break;       // 跳出循环
            }
        }
        // 如果b[j]仍然为-1，说明没有车辆能够满足第j个区县的需求
    }
    for (int j = 1; j <= m; ++j) {
        cout << b[j] << ' ';
    }
    return 0;
}
