#include <iomanip>
#include <iostream>
using namespace std;
int w, n;
int a[15][25];  // a[i][j] 存第i周，编号j的同学的名次
int main() {
    cin >> w >> n;
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            // j 就是名次
            int k;
            cin >> k;  // 编号
            a[i][k] = j;
        }
    }
    int lx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            // i j 是任意两个编号
            int bj = 1;
            for (int k = 1; k <= w; k++) {
                if (a[k][i] >= a[k][j]) {  // 第 k周 i 是否 领先 j
                    bj = 0;
                    break;
                }
            }
            if (bj) {
                lx += 1;
            }
        }
    }
    cout << lx;
    return 0;
}
