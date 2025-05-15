#include <bits/stdc++.h>
#define maxn 15
using namespace std;

int n, r;  // 1-n 中选 r 个数
int a[maxn] = {0};

void prt() {
    for (int i = 1; i <= r; i++) {
        printf("%3d", a[i]);
    }
    printf("\n");
}

void dfs(int k) {
    if (k > r) return prt();  // 输出
    for (int i = a[k - 1] + 1; i <= n; i++) {
        // 元素按由小到大的顺序排列
        // 从上个元素 +1 开始枚举
        // 没有重复的可能，不需要标记数组 vis
        // 当 k=1 的时候从 1 开始枚举，故 a[0] = 0
        a[k] = i;
        dfs(k + 1);
    }
}

int main() {
    cin >> n >> r;
    dfs(1);
    return 0;
}
